#include "token.h"

void Token::setToken(const string &value)
{
    token = value;
}

string Token::getToken() const
{
    return token;
}

string Token::getLexema() const
{
    return lexema;
}

void Token::setLexema(const string &value)
{
    lexema = value;
}

Token::Token()
{

}
