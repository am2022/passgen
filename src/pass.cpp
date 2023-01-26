#include "pass.h"

pass::pass(){
    this->export_to_file = false;
    this->file_name = "";
}

pass::~pass(){
    this->pass_out.close();
}

void pass::creat_pass(char *ch, int len, int start_range = 0, int end_range = 0){
    end_range = len;
    for(int i = start_range;i <= end_range;i++){
        generate(ch, i, "", len, start_range, end_range);
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
        generate(ch, i - 1, pass, len, start_range, end_range);
    }
}

void pass::set_filename(string fname){
    this->export_to_file = true;
    this->file_name = fname;
    this->pass_out.open(this->file_name, ios::app);
}

void pass::set_static_string(string s_string){
    this->static_string = s_string;
}