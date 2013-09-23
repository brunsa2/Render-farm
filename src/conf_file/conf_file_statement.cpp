#include <iostream>

#include "conf_file_statement.h"

using namespace std;

namespace RenderFarm {
    
    ConfFileStatement::ConfFileStatement() : _key(new string("")) {
    }
    
    ConfFileStatement::ConfFileStatement(const ConfFileStatement& other) : ConfFileElement(other), _key(other._key) {
    }
    
    ConfFileStatement::~ConfFileStatement() {
        delete _key;
        _key = NULL;
    }
    
    ConfFileStatement& ConfFileStatement::operator=(ConfFileStatement const &other) {
        if (_key != NULL) {
            delete _key;
        }
        _key = other._key;
        return *this;
    }
    
    void ConfFileStatement::set_key(string *key) {
        if (_key != NULL) {
            delete _key;
        }
        _key = key;
    }
    
    void ConfFileStatement::dump(void) const {
        cout << "<statement><key>" << *_key << "</key></statement>" << endl;
    }
    
}