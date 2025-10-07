#ifndef film_h
#define film_h

#include "Video.h"

struct count_and_chapters {
    int count;
    int* chapters;
    count_and_chapters(int new_count, int* new_chapters) {
        count = new_count;
        chapters = new_chapters;
    }
};

class Film : public Video {
   private:
    int chapters_count;
    int* chapters;

   public:
    virtual ~Film() { delete chapters; };

    Film() { this->setChapters(0, nullptr); };

    Film(std::string name, std::string path_name) : Video(name, path_name) {
        this->setChapters(0, nullptr);
    };

    Film(std::string name, std::string path_name, int length)
        : Video(name, path_name, length) {
        this->setChapters(0, nullptr);
    };

    Film(std::string name, std::string path_name, int length, int count,
         int* tab)
        : Video(name, path_name, length) {
        this->setChapters(count, tab);
    };

    void setChapters(int length, int* tab);
    count_and_chapters getChapters() const;

    void print(std::ostream& s) const;
};

#endif