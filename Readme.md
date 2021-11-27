

# How-to, compile and run:


Note:


There is a Windows version (original) built under Windows 10 with the C++ compiler libraries handled by VisualStudio, need ++17 up.

For Linux, the file path needs are different, and I couldn't get Bazel working with C++17, so there the process and source file is a bit different.  You will find directions for that version under directory `/Linux__sandbox`.

For Windows, assuming your C++ (17...) libraries are good, and you have Npm installed, you can install Bazel/Baselisk globally with Npm, and then, from this directory:

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
