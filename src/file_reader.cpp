#include "file_reader.h"

file_reader::file_reader(){

}

file_reader::~file_reader(){

}

void file_reader::set_filename(string fname){
    this->file_name = fname;
    this->char_in.open(this->file_name);
}