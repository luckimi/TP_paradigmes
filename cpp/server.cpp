//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "Manager.h"
#include "tcpserver.h"

using namespace std;

const int PORT = 3331;

int main(int argc, char* argv[]) {
    Manager manager;

    // Example data in the manager
    int chapters[3] = {1, 2, 3};
    manager.createPhoto("Clement",
                        "~/Desktop/Photos/2025/2025-09-15/Clement.jpg");
    manager.createVideo("traque", "~/Desktop/Traque.mp4", 120);
    manager.createFilm("Epic",
                       "/Users/lucasmichel/Desktop/Telecom_Paris/liste_troll/"
                       "porte_automatique/portes.mp4",
                       180, 3, chapters);

    // Create the TCPServer
    auto* server = new TCPServer([&](string const& request, string& response) {
        cout << "Request: " << request << endl;

        stringstream req(request);
        string command, name;
        req >> command;
        getline(req, name);
        if (!name.empty() && name[0] == ' ') name.erase(0, 1);

        stringstream answer;

        if (command == "find") {
            stringstream temp;
            manager.printMedia(name, temp);
            string result = temp.str();
            if (result.empty()) result = "Object not found";

            // Remove newlines before sending
            for (char& c : result)
                if (c == '\n' || c == '\r') c = ' ';
            response = result;
        } else if (command == "play") {
            manager.playMedia(name);
            response = "Playing " + name;
        } else if (command == "print") {
            std::ostringstream oss;
            manager.printMedia(name, oss);
            response = oss.str();
        } else if (command == "exit") {
            response = "Goodbye";
            cerr << "Server: Client requested disconnection." << endl;
            return false;  // closes connection for this client
        } else {
            response = "Unknown command";
        }

        cout << "Response: " << response << endl;
        return true;  // keep connection alive
    });

    cout << "Starting Server on port " << PORT << endl;

    int status = server->run(PORT);

    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

    return 0;
}
