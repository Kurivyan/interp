#include <iostream>
#include <unordered_map>
#include "lexer.hpp"

std::unordered_map<TokenTypes, std::string> Tokens = {
    {TokenTypes::INDENTIFIERS, "Identifier"},
    {TokenTypes::NUMBER, "Number"},
    {TokenTypes::OPERATOR, "Operator"},
    {TokenTypes::TYPES, "Types"},
    {TokenTypes::RESERVEDWORDS, "Reservedword"},
    {TokenTypes::CharLiteral, "CharLiteral"},
    {TokenTypes::StringLiteral, "StringLiteral"},
    {TokenTypes::LPAREN, "Lparen"},
    {TokenTypes::RPAREN, "Rparen"}};

int main(int argc, char *argv[])
{
    Lexer lexer(argv[1]);
    lexer.tokenize();

    for (auto el : lexer.tokens)
    {
        std::cout << "Token Type: " << Tokens.at(el.type) << ", Value: " << el.name << std::endl;
    }

    return 0;
}