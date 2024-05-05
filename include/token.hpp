#pragma once
#include <string>
enum class TokenTypes
{
    INDENTIFIER,
    INT_LITERAL,
    DOUBLE_LITERAL,
    OPERATOR,
    LPAREN,
    RPAREN,
    RESERVEDWORDS,
    TYPES,
    CHAR_LITERAL,
    STRING_LITERAL,
    BOOL_LITERAL,
    INVALID,
    END
};

struct Token
{
    TokenTypes type;
    std::string name;

    bool operator==(TokenTypes other_token) const
    {
        return type == other_token;
    }

    bool operator==(const std::string &other_name) const
    {
        return name == other_name;
    }
};