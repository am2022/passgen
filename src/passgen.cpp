#include <iostream>
#include <string.h>
#include "pass.cpp"
#include "help.h"
using namespace std;

int main(int argc, char** argv){
    pass p;
    string chs;
    bool export_pass = false;
    string s_export_pass;
    string f_export_pass;
    int argv_chars[3] = {0, 0, 0};
    
    if(argc >= 2){
        for(int i = 1;i < argc;i++){
            if(! strcmp(argv[i], "-char")){
                argv_chars[0] = 1;
            }
            else if(! strcmp(argv[i], "-o")){
                argv_chars[1] = 1;
            }
            else if(! strcmp(argv[i], "-h") || ! strcmp(argv[i], "--help")){
                argv_chars[2] = 1;
            }
        }
    }

    if(argc >= 2){
        for(int i = 1;i < argc;i++){
            if(! strcmp(argv[i], "-char")){
                chs = argv[i+1];
                goto gen;
            }
            else if(! strcmp(argv[i], "-o")){
                f_export_pass = argv[i+1];
                p.set_filename(f_export_pass);

                goto gen;
            }
            else if(! strcmp(argv[i], "-h") || ! strcmp(argv[i], "--help")){
                argv_help();
                return 0;
            }
            else{
                cout<<"wrong input!\n";
                cout<<"type -h or --help for getting help";
                return 0;
            }
        }
    }
    else if(argc == 1){
        goto mainfunc;
    }

    mainfunc:

    cout<<"enter characters:";
    cin>>chs;
    cout<<"do you want to export passlist in a file?(y/n):";
    cin>>s_export_pass;

    if(s_export_pass == "y" || s_export_pass == "yes" || s_export_pass[0] == 'y'){
        export_pass = true;

        cout<<"enter file name:";
        cin>>f_export_pass;

        p.set_filename(f_export_pass);
    }

    gen:

    char ch[chs.length()];
    for(int i = 0;i < chs.length();i++){
        ch[i] = chs[i];
    }

    int len = sizeof(ch) / sizeof(ch[0]);

    p.creat_pass(ch, len);

    return 0;
}