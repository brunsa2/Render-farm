#ifndef CONF_FILE_SECTION
#define CONF_FILE_SECTION

#include <list>

#include "conf_file_element.h"

using namespace std;

namespace RenderFarm {
    class ConfFileSection : public ConfFileElement {
    public:
        ConfFileSection();
        ConfFileSection(const ConfFileSection& other);
        ~ConfFileSection();
        ConfFileSection& operator=(ConfFileSection const &other);
        void set_elements(list<ConfFileElement *> *elements);
        void dump(void) const;
    private:
        list<ConfFileElement *> *_elements;
    };
}

#endif