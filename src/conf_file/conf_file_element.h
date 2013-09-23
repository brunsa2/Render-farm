#ifndef CONF_FILE_ELEMENT
#define CONF_FILE_ELEMENT

using namespace std;

namespace RenderFarm {
    class ConfFileElement {
    public:
        virtual ~ConfFileElement();
        virtual void dump(void) const = 0;
    };
}

#endif