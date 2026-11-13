
#include  <iostream>
#include <fstream>
#include "filelib.h"
#include  <filesystem>
using namespace std;

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
int lineCounter(string name, string dir) {
    ifstream file(defDir() + "\\" + dir +  "\\" + name, ios::in);
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        lineCount++;
    }
    return lineCount;
}

void deleteFile(string name, string dir) {
   string stringPath = defDir() + "\\" + dir + "\\" + name;
    const char* path = stringPath.c_str();
    remove(path);
}



void modifyFile(string name, string dir, string decvar, int lnum) {
    string path = defDir() + "\\" + dir + "\\" + name;
    if (lnum == 0 || lnum < 0) {
        cout << "File " + path + " could not be modified. Invalid line number." << endl;
        return;
    }
    int baseLineCount = lineCounter(name, dir);
    int lineCount = max(lnum, baseLineCount);
    string write[lineCount];
    ifstream inFile(path, ios::in);
    for (int i =0; i < baseLineCount; i++) {
        getline(inFile, write[i]);
    }
    inFile.clear();
    inFile.close();
    write[lnum-1] = decvar;
    remove(path.c_str());
    ofstream outFile(path, ios::trunc);
    for (int i =0; i < lineCount; i++ ) {
        outFile << write[i] << endl;
    }
    outFile.clear();
    outFile.close();

}
void modifyFile(string name, string dir, string decvar) {
    modifyFile(name, dir, decvar, 3);
}







