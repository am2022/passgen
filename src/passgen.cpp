#include <iostream>
#include "pass.cpp"
using namespace std;

int main(){
    pass p;
    string chs;
    cout<<"enter characters:";
    cin>>chs;

    char ch[chs.length()];
    for(int i = 0;i < chs.length();i++){
        ch[i] = chs[i];
    }

    int len = sizeof(ch) / sizeof(ch[0]);

    p.creat_pass(ch, len);

    return 0;
}