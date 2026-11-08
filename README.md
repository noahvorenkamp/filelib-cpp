FEATURES:
C++ File Library

1. bool fileExists(string name): Checks if a file named "name" exists in the build directory. Example: fileExists(message.txt)
3. bool varExists(string name): Creates a folder named "vars" in the build directory and checks whether file "name" exists.
4. string defDir(): Returns the default build directory as a string. Ex: "C:\\...\BUILD\"
6. string varDir(): Returns the "vars" directory and creates it if it doesn't exist. Ex: "C:\\...\BUILD\vars"
7. void createFile(string name, string dir): Creates a subdirectory dir in the build directory and a file named "name" in it. The following is written in the file: 

         1. 01010100011100100111010101100101
         2. MODIFY AT YOUR OWN RISK                                

The first line is a code which spells out TRUE in binary. The second a warning to users to modify at their own risk. The binary code is to ensure that the file was generated automatically,
and is used for the fileStatus() function which checks whether a file has been generated successfully. Example: createFile(mvars.txt, vars) creates the file "C:\\...\BUILD\vars\mvars.txt" with the two default lines mentioned earlier.


8. void createFile(string name, string dir, string decvar): Here it inserts the third line decvar. It generates the file like the previous createFile function but adds a third line with
the string decvar. Example: createFile(mvars.txt, vars, "37$") creates the file "BUILD\vars\mvars.txt" containing the lines

         1. 01010100011100100111010101100101
         2. MODIFY AT YOUR OWN RISK
         3. 37$
10. bool fileStatus(string name, string dir). Checks whether
    
        1. The File Exists
        2. The first line is:
          01010100011100100111010101100101

TO BE IMPLEMENTED: 

X - default versions of existing functions without requiring a dir. (functions applying to base build folder without subdirs)

10. void modifyFile(string name, string dir, string decvar): Replaces the third line of the file "C:\\BUILD\dir\name" with the string decvar.

11. void modifyFile(string name, string dir, string decvar, int lnum): Same as above but lets you choose which line to modify, including line 1 which shouldn't be modified.
 
12. getVar(string name, string dir). Returns line 3 of "C:\\...\BUILD\DIR\name". 



    
