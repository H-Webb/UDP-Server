# 02/10/21

## Picking a framework
After some light research, I found that Qt and ASIO::BOOST to be the larger contenders for networking frameworks. QT seems to be larger and bulkier than my needs where as BOOST has a slimmer overhead, and provides the needed features.

With that I delved to the BOOST Documentation to get an overview before heading in to the coding.

First rpad block is that of the installation of the library. It appears to use it's own builder known as B2 (boost build), so I started to read the documentation for the builder.

### B2
So far the builder is akin to many other builders such as MAKE. A defining feature being that it allows for project wide attributes that cascade into sub-projects, as well as library linking with the need for a call to "LIBS=" (as an example).
As ASIO::Boost reccomends B2 when building with it, I shall use B2 going forward with this project.

Installed locally, added to .gitignore as to allow freedom of installation by other users/devices

## Day Total
Hours: 2

# 04/10/21

## ASIO BOOST tutorials
Starting the tutorial proved to be difficult. Despite the compatibility of Boost's ASIO and B2 libraries, getting used to the B2's JAM language proved slightly more time consuming than planned. This was due to having to learn how to appropriately implement my installation of GCC
and b2.

Now sorted, creating the first tutorial was simple!

### Tutorial 1
Time: 1 hour

### Tutorial 2 & 3
tut 2 went smoothly.
Tutorial 3 took some time as I looking into the Bind functions, specifically their wider purpose and functionality. They seem like very useful operations, specifically for functions you have liitle to no control over and need to work with-in your limits. Or just to allow for more flexibility with-in your code without over encumbering your base.

Time: 1 hour

## Day Total
Time: 2 hour


# 07/10/21

## tutorial 5
Having issues compiling, seems to be that the threads dependancy is not installed. suggestions point to "libboost-thread" needing to be installed but so far I have not found that package. Prehaps an error with the boost installation, a setting incorrect, causing a missing library? 
