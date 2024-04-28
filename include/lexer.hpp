#pragma once
#include <string>
#include <vector>
#include "token.hpp"
#include <unordered_set>
#include <stdexcept>

class Lexer
{
public:
    std::unordered_set<std::string> lang_reserved_word{"if", "else", "while", "for", "do", "return", "break", "continue"};
    std::unordered_set<std::string> lang_type_names{"int", "void", "float", "double", "bool", "char", "long"};
    std::unordered_set<std::string> lang_operators{"+", "-", "/", "*", ".", ",", ";", ">", "<", "="};
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
        " "};

    Lexer(const char *);
    void tokenize();

    bool is_digit(char);
    bool is_alphabetic(char);
    bool is_whitespace(char);
    bool is_operator(char);
    bool is_lparent(char);
    bool is_rparent(char);

    void Extract_Number();
    void Extract_Operator();
    void Extract_Identifier();
    void Extract_StringLiteral();
    void Extract_CharLiteral();

    std::vector<Token> tokens;
    FILE *program;
};