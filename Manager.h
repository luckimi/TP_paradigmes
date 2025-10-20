#ifndef Manager_h
#define Manager_h

#include <map>
#include <memory>
#include <string>
#include <iostream>

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

using namespace std;

class Manager {
   private:
    map<string, shared_ptr<Media>> mediaTable{};
    map<string, shared_ptr<Group>> groupTable{};

   public:
    Manager() {};
    virtual ~Manager() {};

    shared_ptr<Photo> createPhoto(string name, string path_name);
    shared_ptr<Video> createVideo(string name, string path_name, int duration);
    shared_ptr<Film> createFilm(string name, string path_name, int duration, int count, int* chapters);
    shared_ptr<Group> createGroup(string name);

    void printMedia(string name, ostream& s) const;
    void printGroup(string name, ostream& s) const;
    void playMedia(string name) const;
};

#endif
