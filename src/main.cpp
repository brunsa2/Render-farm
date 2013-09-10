#include <iostream>

#include "conf_file/conf_file_reader.h"

using namespace std;

extern int yylex(void);

int main(void) {
    while(1) yylex();
    return 0;
}
