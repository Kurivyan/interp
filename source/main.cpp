#include <iostream>
#include <unordered_map>
#include "lexer.hpp"

std::unordered_map<TokenTypes, std::string> Tokens = {
    {TokenTypes::INDENTIFIER, "Identifier"},
    {TokenTypes::INT_LITERAL, "Integer"},
    {TokenTypes::DOUBLE_LITERAL, "Double"},
    {TokenTypes::OPERATOR, "Operator"},
    {TokenTypes::TYPES, "Types"},
    {TokenTypes::RESERVEDWORDS, "Reservedword"},
    {TokenTypes::CHAR_LITERAL, "Char"},
    {TokenTypes::STRING_LITERAL, "String"},
    {TokenTypes::LPAREN, "Lparen"},
    {TokenTypes::RPAREN, "Rparen"},
    {TokenTypes::BOOL_LITERAL, "Bool"},
    {TokenTypes::INVALID, "Invalid"},
    {TokenTypes::END, "End"}};

int
main(int argc, char *argv[])
{
    Lexer lexer(argv[1]);
    lexer.tokenize();

    for (auto el : lexer.tokens)
    {
        std::cout << "Token Type: " << Tokens.at(el.type) << ", Value: " << el.name << std::endl;
    }

    return 0;
}