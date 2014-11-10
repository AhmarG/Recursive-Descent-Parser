/**
 *Author: Ahmar Gordon
 *Username: gordona
 *
 * Recursive decent parser
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void match(char lookahead, char& curr);
void error();
void Expr(char& curr);
void F(char& curr);
void G(char& curr);
void Term(char& curr);
void H(char& curr);
void Factor(char& curr);
void AddOp(char& curr);
void MulOp(char& curr);
void Number(char& curr);
void I(char& curr);
void Digit(char& curr);

void match(char lookahead, char& curr)
{
    if (curr == lookahead)
        cin.get(curr);
    else error();
}

void error()
{
    cout << "syntax error" << endl;
    exit(1);
}

void Expr(char& curr)
{
    if(isdigit(curr) || curr == '(' || curr == '+'
                || curr == '-')
    {
        F(curr);
        Term(curr);
        G(curr);
    }
    else
    {
        error();
    }
}

void F(char& curr)
{
    if(curr == '+' || curr == '-')
    {
        AddOp(curr);
    }
}

void G(char& curr)
{
    if(curr == '+' || curr == '-')
    {
        AddOp(curr);
        Term(curr);
        G(curr);
    }
}

void Term(char& curr)
{
    if(isdigit(curr) || curr == '(')
    {
        Factor(curr);
        H(curr);
    }
    else
    {
        error();
    }
}

void H(char& curr)
{
    if(curr == '*' || curr == '/')
    {
        MulOp(curr);
        Factor(curr);
        H(curr);
    }
}

void Factor(char& curr)
{
    if(isdigit(curr))
    {
        Number(curr);
    }
    else if(curr == '(')
    {
        match('(', curr);
        Expr(curr);
        match(')', curr);
    }
    else
    {
        error();
    }
}

void AddOp(char& curr)
{
    if(curr == '+')
    {
        match('+', curr);
    }
    else if(curr == '-')
    {
        match('-', curr);
    }
    else
    {
        error();
    }
}

void MulOp(char& curr)
{
    if(curr == '*')
    {
        match('*', curr);
    }
    else if(curr == '/')
    {
        match('/', curr);
    }
    else
    {
        error();
    }
}

void Number(char& curr)
{
    if(isdigit(curr))
    {
        Digit(curr);
        I(curr);
    }
    else
    {
        error();
    }
}

void I(char& curr)
{
    if(isdigit(curr))
    {
        Digit(curr);
        I(curr);
    }
}

void Digit(char& curr)
{
    switch(curr)
    {
        case '0':
            match('0', curr);
            break;
        case '1':
            match('1', curr);
            break;
        case '2':
            match('2', curr);
            break;
        case '3':
            match('3', curr);
            break;
        case '4':
            match('4', curr);
            break;
        case '5':
            match('5', curr);
            break;
        case '6':
            match('6', curr);
            break;
        case '7':
            match('7', curr);
            break;
        case '8':
            match('8', curr);
            break;
        case '9':
            match('9', curr);
            break;
        default:
            error();
            break;
    }
}

int main(void)
{
    char curr;
    cout << "Enter a string for parsing: ";
    cin.get(curr);
    Expr(curr);
    if (curr == '\n')
        cout << "String is in the language." << endl;
    else
        error();
}

