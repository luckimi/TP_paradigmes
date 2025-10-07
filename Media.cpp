#include "Media.h"

Media::~Media() { cerr << "adieu monde cruel\n"; };

string Media::getName() const { return name; };

string Media::getPathName() const { return path_name; };

void Media::setName(string name) { this->name = name; };

void Media::setPathName(string path_name) { this->path_name = path_name; };

void Media::print(std::ostream& s) const {
    s << "Name : " << name << "  Path : " << path_name << '\n';
};
