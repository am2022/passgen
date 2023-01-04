#include "pass.h"

pass::pass(){
    this->export_to_file = false;
    this->file_name = "";
}

pass::~pass(){

}

void pass::creat_pass(char *ch, int len, int start_range, int end_range){
    for(int i = 0;i <= len;i++){
        generate(ch, i, "", len);
    }
}

void pass::generate(char *ch, int i, string s, int len, int start_range, int end_range){
    if(i == 0){
        cout<<s<<"\n";

        if(this->export_to_file == true){
            this->pass_out<<s<<"\n";
        }
        return;
    }

    for(int j = 0;j < len;j++){
        string pass = s + ch[j];
        generate(ch, i - 1, pass, len);
    }
}

void pass::set_filename(string fname){
    this->export_to_file = true;
    this->file_name = fname;
    this->pass_out.open(this->file_name, ios::app);
}