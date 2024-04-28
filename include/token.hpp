#pragma once
#include <string>
enum class TokenTypes
{
    INDENTIFIERS,  // Имена переменных и функций
    NUMBER,        // числа и цифры, цифры и числа
    OPERATOR,      // , / . / > / < / = / + / - / / / * / % / ^
    LPAREN,        // (, [, {
    RPAREN,        // ), ], }
    RESERVEDWORDS, // зарезервированные слова {if, else...}
    TYPES,         // Имена типов
    CharLiteral,   // '
    StringLiteral  // "
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