#include "Video.h"

#include <fstream>
#include <limits>

Video::~Video() { std::cerr << "This video has disappeared\n"; }

void Video::save(std::ofstream& ofs) const {
    ofs << getClassName() << '\n';
    Media::save(ofs);
    ofs << length << '\n';
}

void Video::load(std::ifstream& ifs) {
    Media::load(ifs);
    ifs >> length;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
