#pragma once
#include <string>
#include <vector>
#include "token.hpp"
#include <unordered_set>
#include <stdexcept>

class Lexer
{
public:
    std::unordered_set<std::string> lang_type_names{"int", "void", "float", "double", "bool", "char", "long"};
    std::unordered_set<std::string> lang_reserved_word{"if", "else", "while", "return", "break", "continue"};
    std::unordered_set<std::string> lang_operators{"+", "-", "/", "*", ".", ",", ";", ">", "<", "=", "+=", "-=", "++", "--", ">=", "<=", "=="};
    std::unordered_set<std::string> lang_symbols{
        "\\",
        ",",
        ".",
        "&",
        "*",
        "+",
        "-",
        "_",
        ">",
        "<",
        "=",
        "%",
        "*",
        "^",
        "[",
        "]",
        "(",
        ")",
        "{",
        "}",
        " ",
        ";"};

    Lexer(const char *);
    void tokenize();

    bool is_operator(char) const;
    bool is_lparent(char) const;
    bool is_rparent(char) const;

    void Extract_Number();
    void Extract_Operator();
    void Extract_Identifier();
    void Extract_String();
    void Extract_Char();

    std::vector<Token> tokens;
    FILE *program;
};