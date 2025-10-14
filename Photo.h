#ifndef photo_h
#define photo_h
#include "Media.h"

class Photo : public Media {
   private:
    int latitude{}, longitude{};

   public:
    ~Photo() {cerr << "The SD card is formatted\n";}
    Photo() {};
    Photo(std::string name, std::string path_name)
        : Media(name, path_name) {};

    Photo(std::string name, std::string path_name, int latitude, int longitude)
        : Media(name, path_name), latitude(latitude), longitude(longitude) {};

    void setName(std::string new_name) { Media::setName(new_name); };
    void setPathName(std::string new_path_name) { Media::setPathName(new_path_name); };
    void setPosition(int latitude, int longitude) {
        Photo::latitude = latitude;
        Photo::longitude = longitude;
    };
    void print(std::ostream& s) const {
        s << "Name : " << this->getName() << "  Path : " << this->getPathName()
          << "  Taken at " << latitude << ";" << longitude << '\n';
    };
    void open() const {
        std::string concat = "open " + this->getPathName() + " &";
        const char* command = concat.data();
        system(command);
    };
};

#endif