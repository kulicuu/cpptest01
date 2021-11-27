# How-to, compile and run:

If you are in Debian and have g++ working with ++17 installed and working:

From this directory:

`g++ -std=c++17 cpp/hex_parse.cpp -o hex`

and then (assuming no errors):

`./hex`


I will work on configuring the Bazel toolchain under Debian. For now I've retreated to using g++ from the command line.