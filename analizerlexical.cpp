#include "analizerlexical.h"
#include <QString>
#include <QDebug>


void AnalizerLexical::scanSourceFile()
{
    size_t numberLines = this->linesFile.size();
    for(size_t index = 0; index < numberLines; index++){
        string currentLine = this->linesFile[index];
        scanCurrentLine(currentLine);
    }

}

void AnalizerLexical::scanCurrentLine(const string &line)
{
    for(size_t index = 0; index < line.size(); index++){
        char simbol = line[index];
        automata.switchState(simbol);
        //qDebug() << "Estado actual: " << automata.getActualState() << endl;
    }
    string token;
    automata.assignamentToken(token);
    if(token.length() > 0 ){
        Token tokenToList(token, line);
        listTokensFinded.push_back(tokenToList);
    }
    automata.setActualState(0);

}

AnalizerLexical::AnalizerLexical()
{
    automata = AFD();
}

void AnalizerLexical::startScan(const string &nameFile)
{
    HandleFile fileScan = HandleFile(nameFile);
    fileScan.readSourceFile(this->linesFile);
    scanSourceFile();
}

void AnalizerLexical::printListTokensFinded()
{
    size_t maximumIndex = this->listTokensFinded.size();
    qDebug () << maximumIndex;
    for (size_t index = 0; index < maximumIndex; index++) {
        QString chain = QString::fromStdString(this->listTokensFinded[index].toString());
        qDebug () << chain;
    }
}
