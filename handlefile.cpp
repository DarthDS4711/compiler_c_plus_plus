#include "handlefile.h"
HandleFile::HandleFile(const string &nameFile)
{
    this->pathFileToRead = nameFile;
}

void HandleFile::readSourceFile(vector<string> &sourceFileLines)
{
    ifstream fin(this->pathFileToRead);
    if(fin.is_open()){
        string lineRead;
        fin >> lineRead;
        while(!fin.eof()){
            sourceFileLines.push_back(lineRead);
            fin >> lineRead;
        }
    }
    fin.close();
}
