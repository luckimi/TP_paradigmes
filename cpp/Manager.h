#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include <string>
#include <iostream>

#include "Media.h"
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

    // Media creation
    shared_ptr<Photo> createPhoto(const string& name, const string& path_name);
    shared_ptr<Video> createVideo(const string& name, const string& path_name, int duration);
    shared_ptr<Film> createFilm(const string& name, const string& path_name, int duration, int count, int* chapters);

    // Group creation
    shared_ptr<Group> createGroup(const string& name);

    // Print functions
    void printMedia(const string& name, ostream& s) const;
    void printGroup(const string& name, ostream& s) const;

    // Play media
    void playMedia(const string& name) const;
};

#endif
