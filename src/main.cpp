#include <iostream>
#include <cstdlib>

#include "conf_file/conf_file_reader.h"

using namespace std;

extern int yylex(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "No filename given" << endl;
        exit(EXIT_FAILURE);
    }
    RenderFarm::ConfFileReader mainConfFile = RenderFarm::ConfFileReader(string(argv[1]));
    mainConfFile.parse();
    return 0;
}
