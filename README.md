Features:

1. bool fileExists(string name). Checks if a file named "name" exists in the build directory.
2. bool varExists(string name). Creates a folder named "vars" in the build directory and checks whether file "name" exists.
3. string defDir(): Returns the default build directory as a string.
4. string varDir(): Returns the "vars" directory and creates it if it doesn't exist.
5. void createFile(string name, string dir): Creates a subdirectory dir in the build directory and a file named "name" in it. The following is written in the file: 

   1. 01010100011100100111010101100101
   2.  MODIFY AT YOUR OWN RISK                                
The first line is a code which spells out TRUE in binary. The second a warning to users to modify at their own risk. The binary code is to ensure that the file was generated automatically,
and is used for the fileStatus() function which checks whether a file has been generated successfully.
7. void createFile(string name, string dir, string decvar): Here it inserts the third line decvar. It generates the file like the previous createFile function but adds a third line with
the string decvar.
8. bool fileStatus(string name, string dir). Checks whether
        1. The File Exists
        2. The first line is:
   01010100011100100111010101100101

TO BE IMPLEMENTED: 
9. void modifyFile(string name, string dir, string decvar): Replaces the third line of the file BUILD\dir\name with the string decvar.

10. void modifyFile(string name, string dir, string decvar, int lnum): Same as above but lets you choose which line to modify, including line 1 which shouldn't be modified.
    
