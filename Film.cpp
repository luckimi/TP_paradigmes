#include "Film.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

void Film::setChapters(int length, int* tab) {
    delete[] this->chapters;

    this->chapters_count = length;
    if (length > 0 && tab != nullptr) {
        this->chapters = new int[length];
        for (int i = 0; i < length; i++) {
            this->chapters[i] = tab[i];
        }
    } else {
        this->chapters = nullptr;
    }
}

count_and_chapters Film::getChapters() const {
    return count_and_chapters(this->chapters_count, this->chapters);
}

Film::~Film() {
    delete[] chapters;
    std::cerr << "End of the movie" << '\n';
}

void Film::print(std::ostream& s) const {
    s << "Name : " << this->getName() << "  Path : " << this->getPathName()
      << "  Length " << this->getLength() << '\n';
    s << "Chapters length: ";
    for (int i = 0; i < this->chapters_count; i++) {
        s << this->chapters[i] << ", ";
    }
    s << std::endl;
};

void Film::save(std::ofstream& ofs) const {
    ofs << getClassName() << '\n';
    Media::save(ofs);
    ofs << getLength() << '\n';
    ofs << chapters_count << '\n';
    for (int i = 0; i < chapters_count; ++i) ofs << chapters[i] << ' ';
    ofs << '\n';
}

void Film::load(std::ifstream& ifs) {
    Media::load(ifs);
    int length;
    ifs >> length;
    setLength(length);
    ifs >> chapters_count;
    delete[] chapters;
    if (chapters_count > 0) {
        chapters = new int[chapters_count];
        for (int i = 0; i < chapters_count; ++i) ifs >> chapters[i];
    } else {
        chapters = nullptr;
    }
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}