#include <iostream>
#include <cstdio>
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
        if (std::isdigit(c))
        {
            ungetc(c, program);
            Extract_Number();
            continue;
        }
        if (std::isalpha(c) || c == '_')
        {
            ungetc(c, program);
            Extract_Identifier();
            continue;
        }
        if (std::isblank(c) || c == '\n' || c == '\0' || c == '\r' || c == '\t')
        {
            continue;
        }
        if (is_lparent(c))
        {
            tokens.push_back(Token{TokenType::LPAREN, std::string{c}});
            continue;
        }
        if (is_rparent(c))
        {
            tokens.push_back(Token{TokenType::RPAREN, std::string{c}});
            continue;
        }
        if (is_operator(c))
        {
            ungetc(c, program);
            Extract_Operator();
            continue;
        }
        if (c == '\"')
        {
            Extract_String();
            continue;
        }
        if (c == '\'')
        {
            Extract_Char();
            continue;
        }
        if ((int)c == -1)
            break;
        tokens.push_back(Token{TokenType::INVALID, ""});
    }
    tokens.push_back(Token{TokenType::END, ""});
}

bool Lexer::is_operator(char c) const
{
    if (lang_symbols.contains(std::string{c}))
    {
        return true;
    }
    return false;
}
bool Lexer::is_lparent(char c) const
{
    if (c == '[' || c == '{' || c == '(')
    {
        return true;
    }
    return false;
}
bool Lexer::is_rparent(char c) const
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
    while (std::isdigit(c) && !feof(program))
    {
        res += c;
        c = fgetc(program);
    }
    if (c == '.')
    {
        res += c;
        c = fgetc(program);
        while (std::isdigit(c) && !feof(program))
        {
            res += c;
            c = fgetc(program);
        }
        ungetc(c, program);
        tokens.push_back(Token{TokenType::DOUBLE_LITERAL, res});
        return;
    }
    else
    {
        ungetc(c, program);
    }
    tokens.push_back(Token{TokenType::INT_LITERAL, res});
}

void Lexer::Extract_Identifier()
{
    char c = fgetc(program);
    std::string res;
    while ((std::isalpha(c) || std::isdigit(c) || c == '_') && !feof(program))
    {
        res += c;
        c = fgetc(program);
    }
    ungetc(c, program);
    if (lang_reserved_word.contains(res))
    {
        tokens.push_back(Token{TokenType::RESERVEDWORD, res});
        return;
    }
    if (lang_type_names.contains(res))
    {
        tokens.push_back(Token{TokenType::TYPE, res});
        return;
    }
    if (res == "true" || res == "false")
    {
        tokens.push_back(Token{TokenType::BOOL_LITERAL, res});
        return;
    }
    tokens.push_back(Token{TokenType::IDENTIFIER, res});
}

void Lexer::Extract_Char()
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
    tokens.push_back(Token{TokenType::CHAR_LITERAL, res});
}

void Lexer::Extract_String()
{
    if (feof(program))
        throw std::runtime_error("Exprected char after \".");
    char c = fgetc(program);
    std::string res;
    while (!feof(program) && (std::isalpha(c) || std::isdigit(c) || lang_symbols.contains(std::string{c})))
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
        throw std::runtime_error("Expected \"");
    if (c != '\"')
        throw std::runtime_error("Expected \"");
    tokens.push_back(Token{TokenType::STRING_LITERAL, res});
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
    tokens.push_back(Token{TokenType::OPERATOR, res});
}