
#include  <iostream>
#include <fstream>
using namespace std;
#include "filelib.h"
#include  <filesystem>
bool fileExists(string name) {
    ifstream file(defDir() + "/" + name);
    return file.good();
}
bool varExists(string name) {
    filesystem::create_directory("vars");
    ifstream file(name);
    return file.good();
}
string defDir() {
    namespace fs = filesystem;
    fs::path cwd = fs::current_path();
    return cwd.string();
}
string varDir() {
    namespace fs = filesystem;
    fs::path cwd = fs::current_path();
    filesystem::create_directory("vars");
    return cwd.string() + "\\vars";
}
void createFile(string name, string dir) {
   ofstream file(defDir() + "\\" + dir + "\\" + name, ios::trunc);
    file << "01010100011100100111010101100101" << endl;
    file << "MODIFY AT YOUR OWN RISK" << endl;
    file.close();
}
void createFile(string name, string dir, string decvar) {
    ofstream file(defDir() + "\\" + dir+ "\\" + name, ios::trunc);
    file << "01010100011100100111010101100101" << endl;
    file << "MODIFY AT YOUR OWN RISK" << endl;
    file << decvar << endl;
    file.close();
}
bool fileStatus(string name, string dir) {
    if (fileExists(dir + "\\" + name)) {
        ifstream file(defDir() + "\\" + dir + "\\" + name);
        string line;
        getline(file, line);
        file.close();
        if (line == "01010100011100100111010101100101") {
            return true;
        }


    }
    return false;
}



