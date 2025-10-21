#include "Media.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

Media::~Media() { std::cerr << "adieu monde cruel\n"; }

std::string Media::getName() const { return name; }

std::string Media::getPathName() const { return path_name; }

void Media::setName(const std::string& name) { this->name = name; }

void Media::setPathName(const std::string& path_name) { this->path_name = path_name; }

void Media::print(std::ostream& s) const {
    s << "Name : " << name << "  Path : " << path_name << '\n';
}

std::string Media::getClassName() const { return "Media"; }

void Media::save(std::ofstream& ofs) const {
    ofs << name << '\n';
    ofs << path_name << '\n';
}

void Media::load(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, path_name);
}
