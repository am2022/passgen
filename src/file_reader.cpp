#include "file_reader.h"

file_reader::file_reader(){

}

file_reader::~file_reader(){
    this->char_in.close();
}

void file_reader::set_filename(string fname){
    this->file_name = fname;
    this->char_in.open(this->file_name);
}