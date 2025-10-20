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
    // Inline virtual destructor
    inline virtual ~Video() { std::cerr << "This video has disappeared\n"; }

    // Constructors
    inline Video() {}
    inline Video(std::string name, std::string path_name)
        : Media(name, path_name) {}
    inline Video(std::string name, std::string path_name, int len)
        : Media(name, path_name), length(len) {}

    // Setters and getters (inline)
    inline virtual void setName(std::string new_name) override {
        Media::setName(new_name);
    }
    inline virtual void setPathName(std::string new_path_name) override {
        Media::setPathName(new_path_name);
    }
    inline virtual void setLength(int len) { length = len; }
    inline virtual int getLength() const { return length; }

    // Virtual functions
    inline void print(std::ostream& s) const override {
        s << "Name: " << getName() << "  Path: " << getPathName()
          << "  Length: " << length << "\n";
    }

    inline void open() const override {
        std::string concat = "open " + getPathName() + " &";
        system(concat.c_str());
    }
};

#endif
