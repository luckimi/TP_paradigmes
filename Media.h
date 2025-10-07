#ifndef Media_h
#define Media_h

#include <string.h>

#include <iostream>

using namespace std;

class Media {
   private:
    string name{}, path_name{};

   public:
    Media() {};

    Media(string name, string path_name) : name(name), path_name(path_name) {};

    virtual ~Media();

    virtual string getName() const;
    virtual string getPathName() const;
    virtual void setName(string name);
    virtual void setPathName(string path_name);
    virtual void print(std::ostream& s) const;
    virtual void open() const = 0;
};

#endif