#ifndef LISTTOKENS_H
#define LISTTOKENS_H
#include <vector>
#include "token.h"

class listTokens
{
private:
    vector<Token> listTokensFinded;
public:
    listTokens();
    void addToken(const Token &token);
    void printListTokens();
    vector<Token> &getListTokensFinded();
};

#endif // LISTTOKENS_H
