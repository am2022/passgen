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
        string e_static_string;
        string u_showpass;
    public:
        pass();
        ~pass();
        void creat_pass(char *ch, int len, int start_range, int end_range);
        void generate(char *ch, int i, string s, int len, int start_range, int end_range);
        void set_filename(string fname);
        void set_static_string(string s_string);
        void set_end_static_string(string e_s_string);
        void set_showpass(string showpass);
};

#endif
