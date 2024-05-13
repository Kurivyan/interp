#include <iostream>
#include "parser.hpp"
#include "Abstract Syntax Tree.hpp"

bool Parser::MatchToken(const TokenType &type, const std::string &value = 0)
{
    if (value.empty())
    {
        return tokenslist[offset].type == type;
    }
    else
    {
        return tokenslist[offset].type == type && tokenslist[offset].name == value;
    }
}

void Parser::parse()
{
    while (tokenslist[offset] != TokenType::END)
    {
        std::cout << MatchToken(TokenType::INDENTIFIER, "int") << std::endl;
        offset++;
    }
}