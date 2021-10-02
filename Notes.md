# Thoughts

## Picking a framework
After some light research, I found that Qt and ASIO::BOOST to be the larger contenders for networking frameworks. QT seems to be larger and bulkier than my needs where as BOOST has a slimmer overhead, and provides the needed features.

With that I delved to the BOOST Documentation to get an overview before heading in to the coding.

First rpad block is that of the installation of the library. It appears to use it's own builder known as B2 (boost build), so I started to read the documentation for the builder.

### B2
So far the builder is akin to many other builders such as MAKE. A defining feature being that it allows for project wide attributes that cascade into sub-projects, as well as library linking with the need for a call to "LIBS=" (as an example).
As ASIO::Boost reccomends B2 when building with it, I shall use B2 going forward with this project.