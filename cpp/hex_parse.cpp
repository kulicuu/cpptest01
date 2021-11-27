#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iomanip>


using namespace std;
using namespace std::filesystem;


size_t stat3 (std::string filepath) {
    struct stat buf;
    if (stat(filepath.c_str(), &buf) == -1 ) {
        std::cout << "stat failed" << std::endl;
    } else {
        return buf.st_size;
    }
}


typedef union
{
    float number;
    uint8_t bytes[8];
} FLOATUNION_t;


typedef unsigned long uint32;
uint32 deserialize_uint32(unsigned char *buffer)
{
    uint32 value = 0;
    value |= buffer[0] << 24;
    value |= buffer[1] << 16;
    value |= buffer[2] << 8;
    value |= buffer[3];
    return value;
}


int main () {
    std::string filepath = "../../../../../cpp\\cpptest01.bin";
    size_t size = stat3(filepath);

    vector<unsigned char> bytes2(size, 0);
    ifstream infile(filepath.c_str(), ios::in | ios::binary);
    infile.read((char*)&bytes2[0], bytes2.size());

    unsigned char buff_1[4];
    unsigned char buff_2[6];
    unsigned char buff_3[8];

    for (int m = 0; m < size; m++) {
        
        if ((m == 0) || (m % 18 == 0)) {
            // parse and print results

            for (int i = 0; i < 4; i++) {
                buff_1[i] = bytes2[m + i];
            }

            for (int i = 0; i < 6; i++) {
                buff_2[i] = bytes2[i + 4 + m];
            }

            for (int i = 0; i < 8; i++) {
                buff_3[i] = bytes2[i + 10 + m];
            }

            FLOATUNION_t myFloat;

            for (int i = 0; i < 8; i++) {
                myFloat.bytes[i] = buff_3[i];
            }

            cout << deserialize_uint32(buff_1) << endl;
            cout << buff_2 << endl;
            cout << myFloat.number << endl;
            cout << endl;
        }
    }

    return 0;
 }
