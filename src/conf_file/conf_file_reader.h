#ifndef CONF_FILE_READER
#define CONF_FILE_READER

#include <string>

using namespace std;

namespace RenderFarm {
    class ConfFileReader {
    public:
        ConfFileReader(const string filename);
        void parse(void) const;
    private:
        string _filename;
    };
}

#endif