#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"enter number:";
    cin>>num;

    char ch[num];
    cout<<"enter characters:";
    cin>>ch;

    int len = sizeof(ch) / sizeof(ch[0]);

    return 0;
}