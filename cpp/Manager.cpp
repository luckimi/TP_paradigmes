#include "Manager.h"

// Media creation
shared_ptr<Photo> Manager::createPhoto(const string& name,
                                       const string& path_name) {
    auto photo = make_shared<Photo>(name, path_name);
    mediaTable[name] = photo;
    return photo;
}

shared_ptr<Video> Manager::createVideo(const string& name,
                                       const string& path_name, int duration) {
    auto video = make_shared<Video>(name, path_name, duration);
    mediaTable[name] = video;
    return video;
}

shared_ptr<Film> Manager::createFilm(const string& name,
                                     const string& path_name, int duration,
                                     int count, int* chapters) {
    auto film = make_shared<Film>(name, path_name, duration, count, chapters);
    mediaTable[name] = film;
    return film;
}

// Group creation
shared_ptr<Group> Manager::createGroup(const string& name) {
    auto group = make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

// Print functions
void Manager::printMedia(const string& name, ostream& s) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end())
        it->second->print(s);
    else
        s << "Media not found: " << name << "\n";
}

void Manager::printGroup(const string& name, ostream& s) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end())
        it->second->print(s);
    else
        s << "Group not found: " << name << "\n";
}

// Play media
void Manager::playMedia(const string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end())
        it->second->open();
    else
        cerr << "Media not found: " << name << "\n";
}
