#include <iostream>
#include <unordered_map>
#include <memory>
#include "lexer.hpp"
#include "parser.hpp"

std::unordered_map<TokenType, std::string> TokensList = {
    {TokenType::INDENTIFIER, "Identifier"},
    {TokenType::INT_LITERAL, "Integer"},
    {TokenType::DOUBLE_LITERAL, "Double"},
    {TokenType::OPERATOR, "Operator"},
    {TokenType::TYPES, "Types"},
    {TokenType::RESERVEDWORDS, "Reservedword"},
    {TokenType::CHAR_LITERAL, "Char"},
    {TokenType::STRING_LITERAL, "String"},
    {TokenType::LPAREN, "Lparen"},
    {TokenType::RPAREN, "Rparen"},
    {TokenType::BOOL_LITERAL, "Bool"},
    {TokenType::INVALID, "Invalid"},
    {TokenType::END, "End"}};

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Lexer lexer(argv[1]);
        lexer.tokenize();

        // for (auto el : lexer.tokens)
        // {
        //     std::cout << "Token Type: " << TokensList.at(el.type) << ", Value: " << el.name << std::endl;
        // }

        Parser parser(lexer.tokens);
        parser.parse();
    }
    else
    {
        std::runtime_error("No input file provided.");
    }
    return 0;
}