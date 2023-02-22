# passgen
## passgen or pass generator can make password lists for you
## this is a c++ program so if you want to compile the code you should install g++ on your computer.
## help for argv in passgen:
* Use characters:
>if you want to take characters to passgen in argv; you should use -char and after that, you should write the characters.
><br>use --num after -char to set "0123456789".
><br>use --num-0 after -char to set "123456789".
><br>use --small-letters after -char to set "abcdefghijklmnopqrstuvwxyz".
><br>use --cap-letters after -char to set "ABCDEFGHIJKLMNOPQRSTUVWXYZ".
* Get help:
>if you want to get help for argv in passgen you can type -h or --help.
*  Get output into a file:
>use -o and after that file name that you want to get output at that file.
* config start range:
>use -sr and the start range.
* config end range:
>use -er and end of range number.
* import chars with file:
>use -imp_char and after that file name.
* add a static string:
>use -static_string and after that enter your static string.
* add a static string end of the passwords:
>use -e_static_string and after that enter you static string.
* You should use -exec end of the argv inputs.
>end of the argvs that you use you should put -exec for getting execute.
## how to build passgen?
### first install g++, or any compiler that you prefer.
### after that you should put standard to c++11; if you have g++ you can do it by -std=c++11 after g++.