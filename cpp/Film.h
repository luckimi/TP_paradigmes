#ifndef FILM_H
#define FILM_H

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
    int chapters_count = 0;
    int* chapters = nullptr;

   public:
   virtual ~Film();
    Film() { this->setChapters(0, nullptr); };

    Film(std::string name, std::string path_name)
        : Video(name, path_name) {
        this->setChapters(0, nullptr);
    };

    Film(std::string name, std::string path_name, int length)
        : Video(name, path_name, length) {
        this->setChapters(0, nullptr);
    };

    Film(const std::string& name, const std::string& path_name,
                int length, int count, int* chapters)
        : Video(name, path_name, length) {
        this->setChapters(count, chapters);
    };

    void open() const override {
        std::cout << "Playing film " << getName() << std::endl;
    }
    void setChapters(int length, int* tab);
    count_and_chapters getChapters() const;

    void print(std::ostream& s) const override;
    std::string getClassName() const override { return "Film"; }
    void save(std::ofstream& ofs) const override;
    void load(std::ifstream& ifs) override;
};

#endif