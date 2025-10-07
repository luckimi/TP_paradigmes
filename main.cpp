#include <iostream>

#include "Film.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

void step_5() {
    Video* video = new Video("traque", "~/Desktop/Traque.mp4");
    Photo* photo1 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00168.ARW");
    Photo* photo2 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00169.ARW");
    Photo* photo3 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00170.ARW");
    Photo* photo4 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00171.ARW");
    Photo* photo5 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00172.ARW");
    Photo* photo6 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00173.ARW");
    Photo* photo7 = new Photo("Clement", "~/Desktop/2025-09-15/DSC00174.ARW");
    Media* array[8];
    array[0] = photo1;
    array[1] = video;
    array[2] = photo2;
    array[3] = photo3;
    array[4] = photo4;
    array[5] = photo5;
    array[6] = photo6;
    array[7] = photo7;
    for (int i = 0; i < 8; i++) {
        array[i]->open();
    }
}

void step_6_7() {
    int chapters[3] = {1, 2, 3};
    int chapters2[300];
    for (int i = 0; i < 300; i++) {
        chapters2[i] = 3;
    }
    for (int i = 0; i < 3; i++) {
        cout << chapters[i] << endl;
    }
    Film* movie = new Film("traque", "~/Desktop/Traque.mp4", 59, 3, chapters);

    movie->setChapters(0, nullptr);
    movie->setChapters(300, chapters2);

    movie->print(cout);
    movie->open();
}

int main(int argc, const char* argv[]) {
    

    return 0;
}