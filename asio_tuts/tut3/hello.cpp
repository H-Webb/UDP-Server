#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void print(const boost::system::error_code& /*e*/,
    boost::asio::steady_timer* t, int* count)
{
  if (*count < 5)
  {
    std::cout << *count << std::endl; // print out
    ++(*count);

    //update the timer relative to the previous time so it updates accurately
    // regardless of process time
    t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));

    // set new await but use Bind so that we can get the correct
    // params for the CB function
    t->async_wait(boost::bind(print,
          boost::asio::placeholders::error, t, count));
  }

}

int main(){
  boost::asio::io_context io;
  int count = 0;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));

  t.async_wait(boost::bind(print,
       boost::asio::placeholders::error, &t, &count));

  io.run();

  std::cout << "Final count is " << count << std::endl;
  
  return 0;
}
