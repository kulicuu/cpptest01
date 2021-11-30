#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>


using namespace std;
using namespace std::filesystem;


const char * filepath = "./cpp/cpptest01.bin";


typedef union
{
    double number;
    unsigned char bytes[8];
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


    struct stat buf;
    if (stat(filepath, &buf) == -1 ) {
        cout << "stat failed" << endl;
    } else {
        cout << "file size: " << buf.st_size << endl;
    }

    vector<unsigned char> vector_bytes(buf.st_size, 0);
    ifstream infile(filepath, ios::in | ios::binary);
    infile.read((char*)&vector_bytes[0], vector_bytes.size());

    unsigned char buff_int[4];
    unsigned char buff_text[6];
    unsigned char buff_float[8];

    for (int m = 0; m < buf.st_size; m+=18) {
        
        for (int i = 0; i < 4; i++) {
            buff_int[i] = vector_bytes[m + i];
        }

        for (int i = 0; i < 6; i++) {
            buff_text[i] = vector_bytes[i + 4 + m];
        }

        for (int i = 0; i < 8; i++) {
            buff_float[i] = vector_bytes[i + 10 + m];
        }

        FLOATUNION_t float_union;

        for (int i = 0; i < 8; i++) {
            float_union.bytes[i] = buff_float[i];
        }

        cout << deserialize_uint32(buff_int) << endl;
        cout << buff_text << endl;
        cout << float_union.number << endl;
        cout << endl;

    }

    return 0;
 }
