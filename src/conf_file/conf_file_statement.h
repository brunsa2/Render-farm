#ifndef CONF_FILE_STATEMENT
#define CONF_FILE_STATEMENT

#include <string>

#include "conf_file_element.h"

using namespace std;

namespace RenderFarm {
    class ConfFileStatement : public ConfFileElement {
    public:
        ConfFileStatement();
        ConfFileStatement(const ConfFileStatement& other);
        ~ConfFileStatement();
        ConfFileStatement& operator=(ConfFileStatement const &other);
        void set_key(string *key);
        void dump(void) const;
    private:
        string *_key;
    };
}

#endif