#include "afd.h"
#include <regex>
#include <QDebug>
int AFD::getActualState() const
{
    return actualState;
}

void AFD::setActualState(int value)
{
    actualState = value;
}

void AFD::switchOnStateN0(const char &simbol)
{
    string simbolOne;
    simbolOne.push_back(simbol);
    regex strIdentifying("[a-z]");
    regex strNumber("[0-9]");
    bool flagOne = regex_match(simbolOne, strIdentifying);
    bool flagTwo = regex_match(simbolOne, strNumber);
    if(flagOne){
        actualState = state_identifying;
        return;
    }
    if(flagTwo){
        actualState = state_intNumber;
        return;
    }
    switch (simbol) {
    case '{':
        actualState = state_keyL;
        break;
    case '}':
        actualState = state_keyR;
        break;
    case '/':
        actualState = state_div;
        break;
    case '(':
        actualState = state_parentesisL;
        break;
    case ')':
        actualState = state_parentesisR;
        break;
    case '+':
        actualState = state_sum;
        break;
    case '-':
        actualState = state_rest;
        break;
    case '*':
        actualState = state_mult;
        break;
    case '=':
        actualState = state_assignament;
        break;
    case '<':
    case '>':
        actualState = state_opCompare;
        break;
    case 'F':
        actualState = 16;
        break;
    case 'I':
        actualState = 1;
        break;
    case 'O':
        actualState = 34;
        break;
    case 'W':
        actualState = 9;
        break;
    case ',':
        actualState = state_separator;
        break;
    default:
        actualState = -1;
        break;
    }
}

void AFD::swicthonStateN1(const char &simbol)
{
    switch (simbol) {
    case 'F':
        actualState = state_if;
        break;
    case 'N':
        actualState = state_in;
        break;
    default:
        actualState = -1;
        break;
    }
}

void AFD::switchOnStateN3(const char &simbol)
{
    string simbolOne;
    simbolOne.push_back(simbol);
    regex strIdentifying("(\\w)");
    bool flagOne = regex_match(simbolOne, strIdentifying);
    if(flagOne){
        actualState = state_identifying;
    }
    else{
        actualState = -1;
    }

}

void AFD::switchOnStateN6(const char &simbol)
{
    if(simbol == '/'){
        actualState = state_mod;
    }
    else{
        actualState = -1;
    }
}

void AFD::switchOnStateN9ToN12(const char &simbol)
{
    switch (actualState) {
    case 9:
        if(simbol == 'H')
            actualState = 10;
        else
            actualState = -1;
        break;
    case 10:
        if(simbol == 'I')
            actualState = 11;
        else
            actualState = -1;
        break;
    case 11:
        if(simbol == 'L')
            actualState = 12;
        else
            actualState = -1;
        break;
    case 12:
        if(simbol == 'E')
            actualState = state_while;
        else
            actualState = -1;
        break;
    }
}

void AFD::switchOnStateN14ToN15(const char &simbol)
{
    switch (actualState) {
    case 14:
        if(simbol == 'T')
            actualState = state_int;
        else
            actualState = -1;
        break;
    case 15:
        if(simbol == 'B')
            actualState = state_intBoolean;
        else
            actualState = -1;
        break;
    }
}

void AFD::switchOnStateN16ToN17(const char &simbol)
{
    switch (actualState) {
    case 16:
        switch (simbol) {
        case 'O':
            actualState = 17;
            break;
        case 'L':
            actualState = 19;
            break;
        default:
            actualState = -1;
            break;
        }
        break;
    case 17:
        if(simbol == 'R')
            actualState = state_for;
        else
            actualState = -1;
        break;
    }
}

void AFD::switchOnStateN19ToN21(const char &simbol)
{
    switch (actualState) {
    case 19:
        if(simbol == 'O')
            actualState = 20;
        else
            actualState = -1;
        break;
    case 20:
        if(simbol == 'A')
            actualState = 21;
        else
            actualState = -1;
        break;
    case 21:
        if(simbol == 'T')
            actualState = state_float;
        else
            actualState = -1;
        break;
    }
}

void AFD::switchOnStateN27(const char &simbol)
{
    string simbolOne;
    simbolOne.push_back(simbol);
    regex strNumber("[0-9]");
    bool flagOne = regex_match(simbolOne, strNumber);
    if(flagOne){
        actualState = state_intNumber;
    }
    else{
        actualState = -1;
    }
    if(simbol == '.'){
        actualState = 28;
    }
}

void AFD::switchOnStateN28ToN29(const char &simbol)
{
    string simbolOne;
    simbolOne.push_back(simbol);
    regex strNumber("[0-9]");
    bool flagOne = regex_match(simbolOne, strNumber);
    if(flagOne){
        actualState = state_realNumber;
    }
    else
        actualState = -1;
}

void AFD::switchOnStateN31ToN32(const char &simbol)
{
    switch (actualState) {
    case 31:
        if(simbol == '='){
            actualState = state_equal;
        }
        else
            actualState = -1;
        break;
    case 32:
        if(simbol == '='){
            actualState = state_equalOrCompare;
        }
        else
            actualState = -1;
        break;

    }
}

void AFD::switchOnStateN34ToN35(const char &simbol)
{
    switch (actualState) {
    case 34:
        if(simbol == 'U'){
            actualState = 35;
        }
        else
            actualState = -1;
        break;
    case 35:
        if(simbol == 'T'){
            actualState = state_out;
        }
        else
            actualState = -1;
        break;
    }
}


AFD::AFD()
{
    actualState = 0;
}

void AFD::assignamentToken(string &token)
{
    switch (actualState) {
    case state_if: token = "if"; break;
    case state_identifying: token = "identificador"; break;
    case state_parentesisL: token = "parentesis izquierdo"; break;
    case state_parentesisR: token = "parentesis derecho"; break;
    case state_div: token = "operador division"; break;
    case state_keyL: token = "llave izquierda"; break;
    case state_keyR: token = "llave derecha"; break;
    case state_while: token = "ciclo while"; break;
    case state_in: token = "entrada por consola"; break;
    case state_int: token = "tipo de dato entero"; break;
    case state_for: token = "ciclo for"; break;
    case state_float: token = "tipo de dato punto flotante"; break;
    case state_sum: token = "operador suma"; break;
    case state_rest: token = "operador resta"; break;
    case state_mult: token = "operador multiplicacion"; break;
    case state_mod: token = "operador modulo"; break;
    case state_intNumber: token = "numero constante entero"; break;
    case state_realNumber: token = "numero constante real"; break;
    case state_intBoolean: token = "tipo de dato booleano"; break;
    case state_assignament: token = "operador asignacion"; break;
    case state_opCompare: token = "operador comparacion"; break;
    case state_equal: token = "operador comparacion igualitaria"; break;
    case state_out: token = "salida por consola"; break;
    case state_separator: token = "simbolo de separacion"; break;
    case state_equalOrCompare: token = "operador comparador igual o menor-mayor"; break;
    }
}

void AFD::switchState(const char &simbol)
{
    switch (actualState) {
    case 0: switchOnStateN0(simbol); break;
    case 1: swicthonStateN1(simbol); break;
    case 3: switchOnStateN3(simbol); break;
    case 6: switchOnStateN6(simbol); break;
    case 9:
    case 10:
    case 11:
    case 12: switchOnStateN9ToN12(simbol); break;
    case 14:
    case 15: switchOnStateN14ToN15(simbol); break;
    case 16:
    case 17: switchOnStateN16ToN17(simbol); break;
    case 19:
    case 20:
    case 21: switchOnStateN19ToN21(simbol); break;
    case 27: switchOnStateN27(simbol); break;
    case 28:
    case 29: switchOnStateN28ToN29(simbol); break;
    case 31:
    case 32: switchOnStateN31ToN32(simbol); break;
    case 34:
    case 35: switchOnStateN34ToN35(simbol); break;
    }
}
