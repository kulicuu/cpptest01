


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
