#include <iostream>
#include <string.h>
#include "pass.cpp"
using namespace std;

int main(int argc, char** argv){
    pass p;
    string chs;

    if(argc >= 2){
        for(int i = 1;i < argc;i++){
            if(! strcmp(argv[i], "-char")){
                chs = argv[i+1];
                goto gen;
            }
        }
    }
    else if(argc == 1){
        goto mainfunc;
    }

    mainfunc:

    cout<<"enter characters:";
    cin>>chs;

    gen:

    char ch[chs.length()];
    for(int i = 0;i < chs.length();i++){
        ch[i] = chs[i];
    }

    int len = sizeof(ch) / sizeof(ch[0]);

    p.creat_pass(ch, len);

    return 0;
}