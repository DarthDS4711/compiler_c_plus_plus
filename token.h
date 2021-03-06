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
    Token(const string &token, const string &lexema);
    void setToken(const string &value);
    string getToken() const;

    string getLexema() const;
    void setLexema(const string &value);

    string toString()const;
};

#endif // TOKEN_H
