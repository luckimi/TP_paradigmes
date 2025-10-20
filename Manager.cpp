#include "Manager.h"

shared_ptr<Photo> Manager::createPhoto(string name, string path_name) {
    shared_ptr<Photo> photo = make_shared<Photo>(name, path_name);
    mediaTable[name] = photo;
    return photo;
}

shared_ptr<Video> Manager::createVideo(string name, string path_name, int duration) {
    shared_ptr<Video> video = make_shared<Video>(name, path_name, duration);
    mediaTable[name] = video;
    return video;
}

shared_ptr<Film> Manager::createFilm(string name, string path_name, int duration, int count, int* chapters) {
    shared_ptr<Film> film = make_shared<Film>(name, path_name, duration, count, chapters);
    mediaTable[name] = film;
    return film;
}

shared_ptr<Group> Manager::createGroup(string name) {
    shared_ptr<Group> group = make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void Manager::printMedia(string name, ostream& s) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->print(s);
    } else {
        s << "Media '" << name << "' not found." << endl;
    }
}

void Manager::printGroup(string name, ostream& s) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->print(s);
    } else {
        s << "Group '" << name << "' not found." << endl;
    }
}

void Manager::playMedia(string name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->open();
    } else {
        cerr << "Media '" << name << "' not found." << endl;
    }
}
