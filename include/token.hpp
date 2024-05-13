#pragma once
#include <string>
enum class TokenType
{
    INDENTIFIER,
    RESERVEDWORDS,
    OPERATOR,
    LPAREN,
    RPAREN,
    TYPES,
    INT_LITERAL,
    DOUBLE_LITERAL,
    CHAR_LITERAL,
    STRING_LITERAL,
    BOOL_LITERAL,
    INVALID,
    END
};

struct Token
{
    TokenType type;
    std::string name;

    bool operator==(TokenType other_token) const
    {
        return type == other_token;
    }

    bool operator==(const std::string &other_name) const
    {
        return name == other_name;
    }

    bool operator!=(TokenType other_token) const
    {
        return type != other_token;
    }

    bool operator!=(const std::string &other_name) const
    {
        return name != other_name;
    }
};