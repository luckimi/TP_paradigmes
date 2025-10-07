#include "Film.h"

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

void Film::print(std::ostream& s) const {
    s << "Name : " << this->getName() << "  Path : " << this->getPathName()
      << "  Length " << this->getLength() << '\n';
    s << "Chapters length: ";
    for (int i = 0; i < this->chapters_count; i++) {
        s << this->chapters[i] << ", ";
    }
    s << endl;
};