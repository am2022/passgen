#ifndef PASS_H
#define PASS_H

#pragma once

#include <iostream>
using namespace std;

class pass{
    private:
        bool export_to_file;
        string file_name;
    public:
        pass();
        ~pass();
        void creat_pass(char *ch, int len);
        void generate(char *ch, int i, string s, int len);
};

#endif