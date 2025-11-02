#ifndef MEDIA_H
#define MEDIA_H

#include <fstream>
#include <iostream>
#include <string>

class Media {
    protected:
    std::string name;
    std::string path_name;

   public:
    Media() = default;
    Media(const std::string& name, const std::string& path_name)
        : name(name), path_name(path_name) {}

    virtual ~Media();

    virtual std::string getName() const;
    virtual std::string getPathName() const;
    virtual void setName(const std::string& name);
    virtual void setPathName(const std::string& path_name);

    virtual void print(std::ostream& s) const;
    virtual void open() const = 0;
    virtual std::string getClassName() const;

    virtual void save(std::ofstream& ofs) const;
    virtual void load(std::ifstream& ifs);
};

#endif  // MEDIA_H
