#ifndef HANDLEFILE_H
#define HANDLEFILE_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class HandleFile
{
private:
    string pathFileToRead;
public:
    HandleFile(const string &nameFile);
    void readSourceFile(vector<string> &sourceFileLines);
};

#endif // HANDLEFILE_H
