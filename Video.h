#ifndef VIDEO_H
#define VIDEO_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "Media.h"

class Video : public Media {
   private:
    int length{0};

   public:
   virtual ~Video();
    // Constructors
    Video() {}
    Video(std::string name, std::string path_name)
        : Media(name, path_name) {}
    Video(std::string name, std::string path_name, int len)
        : Media(name, path_name), length(len) {}

    // Setters and getters (inline)
    virtual void setName(const std::string& new_name) override {
        Media::setName(new_name);
    }
    virtual void setPathName(const std::string& new_path_name) override {
        Media::setPathName(new_path_name);
    }
    virtual void setLength(int len) { length = len; }
    virtual int getLength() const { return length; }

    // Virtual functions
    void print(std::ostream& s) const override {
        s << "Name: " << getName() << "  Path: " << getPathName()
          << "  Length: " << length << "\n";
    }

    void open() const override {
        std::string concat = "open " + getPathName() + " &";
        system(concat.c_str());
    }
    std::string getClassName() const override { return "Video"; }
    void save(std::ofstream& ofs) const override;
    void load(std::ifstream& ifs) override;
};

#endif
