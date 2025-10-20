#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <list>

#include "Media.h"

typedef std::shared_ptr<Media> MediaPtr;

class Group : public std::list<MediaPtr> {
   private:
    std::string name{};

   public:
    ~Group() { std::cerr << "Group deleted\n"; }
    Group(std::string new_name) : name(new_name) {}
    std::string getName() const { return name; };

    void push_back(std::shared_ptr<Media> media) {
        list<MediaPtr>::push_back(media);
    }
    void print(std::ostream& s) const {
        s << "Group: " << name << '\n';
        for (auto& it : *this) it->print(s);
    };
};

#endif