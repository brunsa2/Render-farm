#include <iostream>

#include "conf_file_section.h"

using namespace std;

namespace RenderFarm {

    ConfFileSection::ConfFileSection() : _elements(NULL) {
    }

    ConfFileSection::ConfFileSection(const ConfFileSection& other) : ConfFileElement(other), _elements(other._elements) {
    }

    ConfFileSection::~ConfFileSection() {
        while (!_elements->empty()) {
            delete _elements->front();
            _elements->pop_front();
        }
        delete _elements;
        _elements = NULL;
    }

    ConfFileSection& ConfFileSection::operator=(ConfFileSection const &other) {
        if (_elements != NULL) {
            delete _elements;
        }
        _elements = other._elements;
        return *this;
    }

    void ConfFileSection::set_elements(list<ConfFileElement *> *elements) {
        if (_elements != NULL) {
            delete _elements;
        }
        _elements = elements;
    }
    
    void ConfFileSection::dump(void) const {
        cout << "<section>" << endl;
        for (list<ConfFileElement *>::iterator iterator = _elements->begin(); iterator != _elements->end(); iterator++) {
            if (*iterator == NULL) {
                cout << "<statement>null</statement>" << endl;
            } else {
                (*iterator)->dump();
            }
        }
        cout << "</section>" << endl;
    }

}