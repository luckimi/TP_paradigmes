#ifndef PHOTO_H
#define PHOTO_H

#include <cstdlib>
#include <iostream>

#include "Media.h"

class Photo : public Media {
   private:
    int latitude{}, longitude{};

   public:
   virtual ~Photo();

    // Constructors
    Photo() {}
    Photo(std::string name, std::string path_name)
        : Media(name, path_name) {}
    Photo(std::string name, std::string path_name, int latitude,
                 int longitude)
        : Media(name, path_name), latitude(latitude), longitude(longitude) {}

    // Setters
    void setName(const std::string& new_name) override {
        Media::setName(new_name);
    }
    void setPathName(const std::string& new_path_name) override {
        Media::setPathName(new_path_name);
    }
    void setPosition(int lat, int lon) {
        latitude = lat;
        longitude = lon;
    }

    // Virtual functions
    void print(std::ostream& s) const override {
        s << "Name: " << getName() << " Path: " << getPathName()
          << " Taken at: " << latitude << ";" << longitude << "\n";
    }

    void open() const override {
        std::string command = "imagej " + getPathName() + " &";
        system(command.c_str());
    }
    std::string getClassName() const override { return "Photo"; }
    void save(std::ofstream& ofs) const override;
    void load(std::ifstream& ifs) override;
};

#endif
