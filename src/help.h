#include <iostream>
using namespace std;

void argv_help(){
    cout<<"-h or --help for getting help\n";
    cout<<"-char for enter the characters\n";
    cout<<"\t\tyou can use --num to set 0123456789 to chars\n";
    cout<<"\t\tyou can use --num-0 to set 123456789 to chars\n";
    cout<<"\t\tyou can use --small-letters to set abcdefghijklmnopqrstuvwxyz to chars\n";
    cout<<"\t\tyou can use --cap-letters to set ABCDEFGHIJKLMNOPQRSTUVWXYZ to chars\n";
    cout<<"-o for get output file\n";
    cout<<"-sr for config the start range of password list\n";
    cout<<"-er for config the end of password list\n";
    cout<<"-imp_char for import a file for setting chars of password\n";
    cout<<"-static_string for add a static string\n";
    cout<<"-e_static_string for add static string end of the passwords\n";
    cout<<"you can use -showpass and after that you can type y,Y,t,T for see the passwords and other chars for hide them.\n";
    cout<<"you should type -exec end of your inputs";
}