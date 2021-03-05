#ifndef AFD_H
#define AFD_H
#include <iostream>
using namespace std;
class AFD
{
private:
    enum validateStates{
        state_if = 2,
        state_identifying,//3
        state_parentesisL,//4
        state_parentesisR,//5
        state_div,//6
        state_keyL,//7
        state_keyR,//8
        state_while=13,
        state_in,//14
        state_int,//15
        state_for=18,
        state_float=22,
        state_sum,//23
        state_rest,//24
        state_mult,//25
        state_mod,//26
        state_intNumber,//27
        state_realNumber = 29,
        state_intBoolean,//30
        state_assignament,//31
        state_opCompare,//32
        state_equal,//33
        state_out = 36,
        state_separator,//37
    };
    int actualState;
    bool isValidState();
    string lexema;
public:
    AFD();
    void assignamentToken(string &token, string &lexema);
    void switchState(char &simbol);
};

#endif // AFD_H
