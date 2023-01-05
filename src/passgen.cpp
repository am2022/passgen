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
    int s_range;
    int e_range;
    string add_range;
    string sr;
    string er;

    if(argc >= 2){
        for(int i = 1;i < argc;i++){
            if(! strcmp(argv[i], "-char")){
                chs = argv[i+1];
                i++;
            }
            else if(! strcmp(argv[i], "-o")){
                f_export_pass = argv[i+1];
                p.set_filename(f_export_pass);
                i++;
            }
            else if(! strcmp(argv[i], "-sr")){
                sr = argv[i+1];
                s_range = stoi(sr);
                i++;
            }
            else if(! strcmp(argv[i], "-er")){
                er = argv[i+1];
                e_range = stoi(er);
            }
            else if(! strcmp(argv[i], "-exec")){
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

    if(s_export_pass[0] == 'y' || s_export_pass[0] == 'Y'){
        export_pass = true;

        cout<<"enter file name:";
        cin>>f_export_pass;

        p.set_filename(f_export_pass);
    }

    cout<<"do you want to add length range for password list?(y/n):";
    cin>>add_range;

    if(add_range[0] == 'y' || add_range[0] == 'Y'){
        cout<<"enter start of range:";
        cin>>s_range;
        cout<<"enter end of range:";
        cin>>e_range;
    }

    gen:

    char ch[chs.length()];
    for(int i = 0;i < chs.length();i++){
        ch[i] = chs[i];
    }

    int len = sizeof(ch) / sizeof(ch[0]);

    p.creat_pass(ch, len, s_range, e_range);

    return 0;
}