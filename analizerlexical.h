#ifndef ANALIZERLEXICAL_H
#define ANALIZERLEXICAL_H
#include <vector>
#include <cstring>
#include "token.h"
#include "handlefile.h"
#include "afd.h"
class AnalizerLexical
{
private:
    vector<Token> listTokensFinded;
    vector<string> linesFile;
    AFD automata;
    bool statusToken(const char &lexima);
    void scanSourceFile();
    void scanCurrentLine(const string &line);
public:
    AnalizerLexical();
    void startScan(const string &nameFile);
    void validateToken(const char &lexima);
    void printListTokensFinded();

};

#endif // ANALIZERLEXICAL_H
