#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;
class Token
{
private:
    string token;
    string lexema;
public:
    Token();
    void setToken(const string &value);
    string getToken() const;

    string getLexema() const;
    void setLexema(const string &value);
};

#endif // TOKEN_H
