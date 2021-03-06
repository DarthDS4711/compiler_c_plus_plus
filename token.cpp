#include "token.h"
#include <sstream>

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

string Token::toString() const
{
    stringstream ss;
    ss << "Token : " << token << " valor: " << lexema << endl;
    return ss.str();
}

Token::Token(const string &token, const string &lexema)
{
    this->token = token;
    this->lexema = lexema;
}
