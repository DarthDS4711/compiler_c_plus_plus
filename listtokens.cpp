#include "listtokens.h"

vector<Token> &listTokens::getListTokensFinded()
{
    return listTokensFinded;
}
void listTokens::addToken(const Token &token)
{
    listTokensFinded.push_back(token);
}
