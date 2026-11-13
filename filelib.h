//Includes
using namespace std;
//start of header guard
#ifndef UNTITLED_FILELIB_H
//define to somehow prevent multilple inclusions
#define UNTITLED_FILELIB_H

// Function declarations
bool fileExists(string name);  // Function that checks whether file exists.
bool varExists(string name); // Function that checks whether file in var folder exists.
string defDir(); // Gives you the default build directory
string varDir();  // Gives you the directory of the variables folder (within the build), creates if does not exist
void createFile(string name, string dir); //creates a file called name at build folder \ dir
void createFile(string name, string dir, string );
bool fileStatus(string name, string dir);
int lineCounter(string name, string dir);
void deleteFile(string name, string dir);
void modifyFile(string name, string dir, string decvar);
void modifyFile(string name, string dir, string decvar, int lnum);


#endif //UNTITLED_FILELIB_H
