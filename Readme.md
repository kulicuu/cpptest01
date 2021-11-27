

# How-to, compile and run:

There is a Windows version and a Linux version.  


## Linux:

The Linux version and instructions can be found in the `\Linux__sandbox` directory.


## Windows:

Assuming your C++ 17 libraries are good (VisualStudio handles this very well), and you have Npm installed, you can install Bazel/Baselisk globally with Npm (`npm i -g bazel/bazelisk`).  

Then, from this directory:

`bazel run cpp:hex-parse`



______________________________________________________________________


# Exercise Requirements:


You have been given a data file containing a list of known non-local
metaparticles.

The format of the data file is an array of interleaved structures representing
the following data for each record:

* a 32-bit unsigned integer (4 bytes)
* 6 bytes of ASCII string, null-terminated
* a 64-bit floating point number (8 bytes)

All scalar values are encoded big-endian.

Write a program to read the data and print each record with each field on its
own line, and a blank line after each record.  For example, two records might
look like:

```
555
AX-88
6.35

885
OK-01
3.141

```

Your program must print all of the records in the file.
