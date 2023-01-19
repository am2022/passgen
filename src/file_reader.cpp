#include "file_reader.h"

file_reader::file_reader(){
    this->file_name = "";
}

file_reader::file_reader(string fname){
    this->set_filename(fname);
}

file_reader::~file_reader(){
    this->char_in.close();
}

int file_reader::set_filename(string fname){
    this->file_name = fname;
    this->char_in.open(this->file_name);
}

string file_reader::read_file(){
    char buff[MAX_READ_SIZE];
    int i = 0;
    string s_buff;

    while(! this->char_in.eof()){
        this->char_in>>buff[i];
        i++;

        if(i > MAX_READ_SIZE){
            cout<<"passgen can't open this file; because file is too big!";
        }
    }

    for(int j = 0;buff[j] != '\0';j++){
        s_buff += buff[j];
    }

    return s_buff;
}

int file_reader::is_file_valid(string fname){
    ifstream file(fname);

    if(! file){
        return 1;
    }
    else{
        return 0;
    }
}