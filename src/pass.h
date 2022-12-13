#ifndef PASS_H
#define PASS_H

#pragma once

#include <iostream>
using namespace std;

class pass{
    private:
    public:
        pass();
        ~pass();
        void creat_pass(char *ch, int len);
        void generate(char *ch, int i, string s, int len);
};

#endif