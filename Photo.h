#ifndef PHOTO_H
#define PHOTO_H

#include <cstdlib>
#include <iostream>

#include "Media.h"

class Photo : public Media {
   private:
    int latitude{}, longitude{};

   public:
    // Inline virtual destructor
    inline virtual ~Photo() { std::cerr << "The SD card is formatted\n"; }

    // Constructors
    inline Photo() {}
    inline Photo(std::string name, std::string path_name)
        : Media(name, path_name) {}
    inline Photo(std::string name, std::string path_name, int latitude,
                 int longitude)
        : Media(name, path_name), latitude(latitude), longitude(longitude) {}

    // Setters
    inline void setName(std::string new_name) { Media::setName(new_name); }
    inline void setPathName(std::string new_path_name) {
        Media::setPathName(new_path_name);
    }
    inline void setPosition(int lat, int lon) {
        latitude = lat;
        longitude = lon;
    }

    // Virtual functions
    inline void print(std::ostream& s) const override {
        s << "Name: " << getName() << " Path: " << getPathName()
          << " Taken at: " << latitude << ";" << longitude << "\n";
    }

    inline void open() const override {
        std::string command = "open " + getPathName() + " &";
        system(command.c_str());
    }
};

#endif
