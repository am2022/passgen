#ifndef PASS_H
#define PASS_H

#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class pass{
    private:
        bool export_to_file;
        string file_name;
        ofstream pass_out;
        string static_string;
    public:
        pass();
        ~pass();
        void creat_pass(char *ch, int len, int start_range, int end_range);
        void generate(char *ch, int i, string s, int len, int start_range, int end_range);
        void set_filename(string fname);
        void set_static_string(string s_string);
};

#endif