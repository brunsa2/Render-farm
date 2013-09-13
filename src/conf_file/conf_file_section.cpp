#include <iostream>

#include "conf_file_section.h"

using namespace std;

namespace RenderFarm {

    ConfFileSection::ConfFileSection() : _elements(NULL) {
        cout << "Create section" << endl;
    }

    ConfFileSection::ConfFileSection(const ConfFileSection& other) : ConfFileElement(other), _elements(other._elements) {
    }

    ConfFileSection::~ConfFileSection() {
        cout << "Delete section" << endl;
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

}