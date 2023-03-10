#include <iostream>
#include <string.h>
#include "pass.cpp"
#include "file_reader.cpp"
#include "help.h"
#include "ascii_art.h"
using namespace std;

int main(int argc, char** argv){
    pass p;
    string chs;
    string a_chs;       //ask for chs file
    string f_chs;       //for getting chs file
    bool export_pass = false;
    string s_export_pass;
    string f_export_pass;
    int s_range;
    int e_range;
    string add_range;
    string sr;
    string er;
    string static_string; //used for static string in password list
    string a_static_string;
    string e_static_string; //used for static string in end of the password
    string a_e_static_string; //used for ask user for static string in end of the password
    string a_showpass; //this var is for asking user to show generated passwords
    string showpass;

    if(argc >= 2){
        for(int i = 1;i < argc;i++){
            if(! strcmp(argv[i], "-char")){
                chs = argv[i+1];

                if(chs == "--num"){
                    chs = "";
                    chs = "0123456789";
                }
                else if(chs == "--num-0"){
                    chs = "";
                    chs = "123456789";
                }
                else if(chs == "--small-letters"){
                    chs = "";
                    chs = "abcdefghijklmnopqrstuvwxyz";
                }
                else if(chs == "--cap-letters"){
                    chs = "";
                    chs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                }

                i++;
            }
            else if(! strcmp(argv[i], "-o")){
                f_export_pass = argv[i+1];
                p.set_filename(f_export_pass);
                i++;
            }
            else if(! strcmp(argv[i], "-sr")){
                sr = string(argv[i+1]);
                s_range = stoi(sr);
                add_range[0] = 'y';

                if(s_range > chs.length()){
                    cout<<"your input start range, is more than length of characters you entered!\n";
                    return 0;
                }

                i++;
            }
            else if(! strcmp(argv[i], "-er")){
                er = string(argv[i+1]);
                e_range = stoi(er);
                add_range[0] = 'y';

                if(e_range > chs.length()){
                    cout<<"your input end range, is more than length of characters you entered!\n";
                    return 0;
                }

                i++;
            }
            else if(! strcmp(argv[i], "-imp_char")){
                f_chs = string(argv[i+1]);

                file_reader read;

                if(! read.set_filename(f_chs)){
                    return 0;
                }

                chs = read.read_file();

                i++;
            }
            else if(! strcmp(argv[i], "-static_string")){
                static_string = string(argv[i+1]);

                i++;
            }
            else if(! strcmp(argv[i], "-e_static_string")){
                e_static_string = string(argv[i+1]);

                i++;
            }
            else if(! strcmp(argv[i], "-showpass")){
                showpass = string(argv[i+1]);

                if(showpass[0] == 'T' || showpass[0] == 't' || showpass[0] == 'Y' || showpass[0] == 'y'){
                    p.set_showpass("y");
                }
                else{
                    p.set_showpass("n");
                }

                i++;
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

    ascii_art();
    cout<<"\n";

    cout<<"do you want to import list of characters?(y/n):";
    cin>>a_chs;

    if(a_chs[0] == 'y' || a_chs[0] == 'Y'){
        get_import_file:

        cout<<"enter file name:";
        cin>>f_chs;

        file_reader reader;

        if(! reader.set_filename(f_chs)){
            goto get_import_file;
        }

        chs = reader.read_file();
    }
    else{
        cout<<"enter characters:";
        cin>>chs;
    }

    cout<<"do you want to add a static string?(y/n):";
    cin>>a_static_string;

    if(a_static_string[0] == 'y' || a_static_string[0] == 'Y'){
        cout<<"enter static string:";
        cin>>static_string;

        p.set_static_string(static_string);
    }

    cout<<"do you want to add a static string for end?(y/n):";
    cin>>a_e_static_string;

    if(a_e_static_string[0] == 'y' || a_e_static_string[0] == 'Y'){
        cout<<"enter static string for end:";
        cin>>e_static_string;

        p.set_end_static_string(e_static_string);
    }

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

    cout<<"do you want to see passwords that created?(y/n):";
    cin>>a_showpass;

    if(a_showpass[0] == 'y' || a_showpass[0] == 'Y'){
        showpass = "y";
        p.set_showpass("y");
    }
    else{
        showpass = "n";
        p.set_showpass("n");
    }

    gen:

    char ch[chs.length()];
    for(int i = 0;i < chs.length();i++){
        ch[i] = chs[i];
    }

    int len = sizeof(ch) / sizeof(ch[0]);

    if(add_range[0] == 'y' || add_range[0] == 'Y'){
        p.creat_pass(ch, len, s_range, e_range);
    }
    else{
        p.creat_pass(ch, len);
    }

    return 0;
}
