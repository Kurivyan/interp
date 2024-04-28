#include <iostream>
#include "lexer.hpp"

Lexer::Lexer(const char *filename)
{
    program = fopen(filename, "r");
}

void Lexer::tokenize()
{
    char c;
    while (!feof(program))
    {
        c = fgetc(program);
        if (is_digit(c))
        {
            ungetc(c, program);
            Extract_Number();
        }
        if (is_alphabetic(c) || c == '_')
        {
            ungetc(c, program);
            Extract_Identifier();
        }
        if (is_whitespace(c))
        {
            continue;
        }
        if (is_operator(c))
        {
            ungetc(c, program);
            Extract_Operator();
        }
        if (is_lparent(c))
        {
            tokens.push_back(Token{TokenTypes::LPAREN, std::string{c}});
            continue;
        }
        if (is_rparent(c))
        {
            tokens.push_back(Token{TokenTypes::RPAREN, std::string{c}});
            continue;
        }
        if (c == '\"')
        {
            Extract_StringLiteral();
        }
        if (c == '\'')
        {
            Extract_CharLiteral();
        }
    }
}

bool Lexer::is_digit(char c)
{
    if (c <= '9' && c >= '0')
    {
        return true;
    }
    return false;
}
bool Lexer::is_alphabetic(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}
bool Lexer::is_whitespace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return true;
    return false;
}
bool Lexer::is_operator(char c)
{
    if (lang_operators.contains(std::string{c}))
    {
        return true;
    }
    return false;
}
bool Lexer::is_lparent(char c)
{
    if (c == '[' || c == '{' || c == '(')
    {
        return true;
    }
    return false;
}
bool Lexer::is_rparent(char c)
{
    if (c == ']' || c == ')' || c == '}')
    {
        return true;
    }
    return false;
}

void Lexer::Extract_Number()
{
    char c = fgetc(program);
    std::string res;
    while (is_digit(c) && !feof(program))
    {
        res += c;
        c = fgetc(program);
    }
    if (c == '.')
    {
        res += c;
        c = fgetc(program);
        while (is_digit(c) && !feof(program))
        {
            res += c;
            c = fgetc(program);
        }
        ungetc(c, program);
    }
    else
    {
        ungetc(c, program);
    }
    tokens.push_back(Token{TokenTypes::NUMBER, res});
}

void Lexer::Extract_Identifier()
{
    char c = fgetc(program);
    std::string res;
    while ((is_alphabetic(c) || is_digit(c) || c == '_') && !feof(program))
    {
        res += c;
        c = fgetc(program);
    }
    ungetc(c, program);
    if (lang_reserved_word.contains(res))
    {
        tokens.push_back(Token{TokenTypes::RESERVEDWORDS, res});
        return;
    }
    if (lang_type_names.contains(res))
    {
        tokens.push_back(Token{TokenTypes::TYPES, res});
        return;
    }
    tokens.push_back(Token{TokenTypes::INDENTIFIERS, res});
}

void Lexer::Extract_CharLiteral()
{
    if (feof(program))
        throw std::runtime_error("Expected char after \'");
    char c = fgetc(program);
    std::string res;

    if (c == '\\')
    {
        c = fgetc(program);
        if (c == '\\' || c == '\"' || c == '\'')
        {
            res += c;
        }
        else
        {
            throw std::runtime_error("Exprecte char.");
        }
    }
    else
    {
        res += c;
    }

    if (feof(program))
        throw std::runtime_error("Expected \'.");
    c = fgetc(program);
    if (c != '\'')
        throw std::runtime_error("Expected \'.");
    tokens.push_back(Token{TokenTypes::CharLiteral, res});
}

void Lexer::Extract_StringLiteral()
{
    if (feof(program))
        throw std::runtime_error("Exprected char after \".");
    char c = fgetc(program);
    std::cout << c << std::endl;
    std::string res;
    while (!feof(program) && (is_alphabetic(c) || is_digit(c) || lang_symbols.contains(std::string{c})))
    {
        if (c == '\\')
        {
            c = fgetc(program);
            if (c == '\\' || c == '\"' || c == '\'')
            {
                res += c;
            }
            else
            {
                throw std::runtime_error("Exprecte specific char after \\ .");
            }
        }
        else
        {
            res += c;
        }
        c = fgetc(program);
    }
    if (feof(program))
        throw std::runtime_error("Expected 1\"");
    if (c != '\"')
        throw std::runtime_error("Expected 2\"");
    tokens.push_back(Token{TokenTypes::StringLiteral, res});
}

void Lexer::Extract_Operator()
{
    char c = fgetc(program);
    std::string res;
    res += c;
    if ((c == '=' || c == '>' || c == '<') && !feof(program))
    {
        c = fgetc(program);
        if (c == '=')
            res += c;
        else
            ungetc(c, program);
    }
    tokens.push_back(Token{TokenTypes::OPERATOR, res});
}