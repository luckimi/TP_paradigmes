#include "Photo.h"
#include <fstream>
#include <limits>

Photo::~Photo() {std::cerr << "The SD card is formatted\n"; }

void Photo::save(std::ofstream& ofs) const {
    ofs << getClassName() << '\n'; // store class type
    Media::save(ofs);
    ofs << latitude << ' ' << longitude << '\n';
}

void Photo::load(std::ifstream& ifs) {
    Media::load(ifs);
    ifs >> latitude >> longitude;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip to next line
}
