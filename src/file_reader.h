#ifndef FILE_READER_H
#define FILE_READER_H

#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class file_reader{
    private:
        string file_name;
        ifstream char_in;
    public:
        file_reader();
        ~file_reader();
        void set_filename(string fname);
        string read_file();
};

#endif