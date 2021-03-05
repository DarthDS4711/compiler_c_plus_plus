#ifndef ANALIZERLEXICAL_H
#define ANALIZERLEXICAL_H
#include <vector>
#include "token.h"
#include "language.h"
class analizerLexical
{
private:
    vector<Token> listTokensFinded;
    Language chainsValidate;
    bool statusToken(const char &lexima);
public:
    analizerLexical();
    void validateToken(const char &lexima);
};

#endif // ANALIZERLEXICAL_H
