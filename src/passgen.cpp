#include <iostream>
#include "pass.cpp"
using namespace std;

int main(){
    pass p;

    int num;
    cout<<"enter number:";
    cin>>num;

    char ch[num];
    cout<<"enter characters:";
    cin>>ch;

    int len = sizeof(ch) / sizeof(ch[0]);

    p.creat_pass(ch, len);

    return 0;
}