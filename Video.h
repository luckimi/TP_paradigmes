#ifndef video_h
#define video_h

#include "Media.h"

class Video : public Media {
   private:
    int length{};

   public:
    Video() {};

    Video(std::string name, std::string path_name) : Media(name, path_name) {};

    Video(std::string name, std::string path_name, int length)
        : Media(name, path_name), length(length) {};

    virtual void setName(std::string new_name) { Media::setName(new_name); };
    virtual void setPathName(std::string new_path_name) {
        Media::setPathName(new_path_name);
    };
    virtual void setLength(int length) { Video::length = length; };
    virtual int getLength() const { return length; };
    void print(std::ostream& s) const {
        s << "Name : " << this->getName() << "  Path : " << this->getPathName()
          << "  Length " << length << '\n';
    };
    void open() const {
        string concat = "open " + this->getPathName() + "&";
        const char* command = concat.data();
        system(command);
    };
};

#endif