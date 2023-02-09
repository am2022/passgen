#include <iostream>
using namespace std;

void argv_help(){
    cout<<"-h or --help for getting help\n";
    cout<<"-char for enter the characters\n";
    cout<<"-o for get output file\n";
    cout<<"-sr for config the start range of password list\n";
    cout<<"-er for config the end of password list\n";
    cout<<"-imp_char for import a file for setting chars of password\n";
    cout<<"-static_string for add a static string\n";
    cout<<"-e_static_string for add static string end of the passwords\n";
    cout<<"you should type -exec end of your inputs";
}