//#include <cstdio>

#include "conf_file_reader.h"

using namespace std;

extern int yyparse(void);
extern FILE *yyin;

RenderFarm::ConfFileReader::ConfFileReader(const string filename) : _filename(filename) { }

void RenderFarm::ConfFileReader::parse(void) const {
    yyin = fopen(_filename.c_str(), "r");
    yyparse();
}