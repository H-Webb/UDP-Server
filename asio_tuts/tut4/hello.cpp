#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

class printer
{
public:
  printer(boost::asio::io_context& io)
   : timer_(io, boost::asio::chrono::seconds(1)),
     count_(0)
     {
       timer_.async_wait(boost::bind(&printer::print, this));
     }

  ~printer()
  {
    std::cout << "Final count is " << count_ << std::endl;
  }

  void print()
  {
    if (count_ < 5)
    {
      std::cout << count_ << std::endl;
      ++count_;

      timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
      timer_.async_wait(boost::bind(&printer::print, this));
    }
  }

  private:
  boost::asio::steady_timer timer_;
  int count_;
  };

/*
void print(const boost::system::error_code& /*e,
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
*/

int main()
{
  boost::asio::io_context io;
  printer p(io);
  io.run();

  return 0;
}
