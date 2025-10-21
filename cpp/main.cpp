#include <iostream>
#include <list>

#include "Film.h"
#include "Group.h"
#include "Photo.h"
#include "Video.h"
#include "Manager.h"

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
    cout << "test0" << endl;
    cout << chapters << endl;

    Film movie = Film("traque", "~/Desktop/Traque.mp4", 59, 3, chapters);
    cout << "test1" << endl;

    movie.setChapters(0, nullptr);
    cout << "test" << endl;
    movie.setChapters(300, chapters2);

    movie.print(cout);
    movie.open();
}

void step_8() {
    Video* video_1 = new Video("traque", "~/Desktop/Traque.mp4");
    std::shared_ptr<Media> video(video_1);
    Photo* photo_1 =
        new Photo("Clement", "~/Desktop/Photos/2025/2025-09-15/Clement.jpg");
    std::shared_ptr<Media> photo1(photo_1);
    Photo* photo_2 =
        new Photo("Khalil", "~/Desktop/Photos/2025/2025-09-15/Khalil.jpg");
    std::shared_ptr<Media> photo2(photo_2);
    Photo* photo_3 = new Photo(
        "Quentin loin", "~/Desktop/Photos/2025/2025-09-15/Quentin_loin.jpg");
    std::shared_ptr<Media> photo3(photo_3);
    Photo* photo_4 =
        new Photo("Quentin", "~/Desktop/Photos/2025/2025-09-15/Quentin.jpg");
    std::shared_ptr<Media> photo4(photo_4);
    Photo* photo_5 =
        new Photo("STY", "~/Desktop/Photos/2025/2025-09-15/STY.jpg");
    std::shared_ptr<Media> photo5(photo_5);
    Group moustache = Group("Moustache");
    moustache.push_back(photo1);
    moustache.push_back(photo3);
    moustache.push_back(photo4);
    Group all = Group("Tout le monde");
    all.push_back(video);
    all.push_back(photo1);
    all.push_back(photo2);
    all.push_back(photo3);
    all.push_back(photo4);
    all.push_back(photo5);
    {
        Group buro = Group("Buro!");
        buro.push_back(photo1);
        buro.push_back(photo2);
        buro.print(std::cout);
    }
    {
        Group loin = Group("Loin!");
        Photo* photo_6 =
            new Photo("Quentin loin",
                      "~/Desktop/Photos/2025/2025-09-15/Quentin_loin.jpg");
        std::shared_ptr<Media> photo6(photo_6);
        loin.push_back(photo6);
        loin.print(std::cout);
    }
    moustache.print(std::cout);
    all.print(std::cout);
}

void step_10(){
    Manager manager;

    auto photo1 = manager.createPhoto("Clement", "~/Desktop/Photos/2025/2025-09-15/Clement.jpg");
    auto video1 = manager.createVideo("traque", "~/Desktop/Traque.mp4", 120);

    int chapters[] = {1, 2, 3};
    auto film1 = manager.createFilm("traque2", "~/Desktop/Traque.mp4", 300, 3, chapters);

    auto group1 = manager.createGroup("Favorites");
    group1->push_back(photo1);
    group1->push_back(video1);

    manager.printMedia("Clement", cout);
    manager.printGroup("Favorites", cout);

    manager.playMedia("traque");
}

int main(int argc, const char* argv[]) {
    step_10();

    return 0;
}