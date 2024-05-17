#include <iostream>
#include <memory>
#include "parser.hpp"
#include "AbstractSyntaxTree.hpp"

bool Parser::MatchToken(const TokenType &type, const std::string &name)
{
    if (name.empty())
    {
        return tokenslist[offset].type == type;
    }
    else
    {
        return tokenslist[offset].type == type && tokenslist[offset].name == name;
    }
}

bool Parser::MatchToken(const std::vector<Token>::iterator &it,
                        const TokenType &type,
                        const std::string &name)
{
    if (name.empty())
    {
        return (*it).type == type;
    }
    else
    {
        return (*it).type == type && (*it).name == name;
    }
}

void Parser::parse()
{
    while (!MatchToken(TokenType::END))
    {
        std::shared_ptr<DeclarationNode> decl = ExpectDeclaration();
        if (decl != nullptr)
        {
            ASTresult.push_back(decl);
        }
        else
        {
            std::runtime_error("Error: Expected declaration");
        }
    }
}

/*************************
 *     Exprectations     *
 *************************/
std::shared_ptr<DeclarationNode> Parser::ExpectDeclaration()
{
    std::vector<Token>::iterator it = tokenslist.begin() + offset;
    if (MatchToken(it, TokenType::TYPE))
    {
        ++it;
        if (MatchToken(it, TokenType::IDENTIFIER))
        {
            ++it;
            if (MatchToken(it, TokenType::OPERATOR, "=") ||

                MatchToken(it, TokenType::OPERATOR, ";"))
            {
                return parse_variabledeclaration();
            }
            else if (MatchToken(it, TokenType::LPAREN, "("))
            {
                return parse_functiondeclaration();
            }
        }
        else
        {
            std::runtime_error("Exprected Identifier after Type.");
        }
    }
    else
    {
        std::runtime_error("Expected Declaratino.");
    }
    return nullptr;
}

std::shared_ptr<ExpressionNode> Parser::ExpectExpression()
{
    std::vector<Token>::iterator it = tokenslist.begin() + offset;
    if (MatchToken(it, TokenType::BOOL_LITERAL) ||
        MatchToken(it, TokenType::CHAR_LITERAL) ||
        MatchToken(it, TokenType::DOUBLE_LITERAL) ||
        MatchToken(it, TokenType::INT_LITERAL))
    {
        return parse_literal();
    }
    return nullptr;
}
std::shared_ptr<StatementNode> Parser::ExpectStatement()
{
    return nullptr;
}

/*************************
 *     Declarations      *
 *************************/

std::shared_ptr<VariableDeclaration> Parser::parse_variabledeclaration()
{

    std::string type = tokenslist[offset].name;
    offset++;
    std::vector<std::shared_ptr<DeclList>> declList;
    std::shared_ptr<DeclList> declaration = ExpectDeclList();
    while (declaration != nullptr)
    {
        declList.push_back(declaration);
        declaration = ExpectDeclList();
    }
    return std::make_shared<VariableDeclaration>(VariableDeclaration(type, declList));
}

std::shared_ptr<DeclList> Parser::ExpectDeclList()
{
    if (MatchToken(TokenType::OPERATOR, ",") || MatchToken(TokenType::OPERATOR, ";"))
        offset++;
    std::vector<Token>::iterator it = tokenslist.begin() + offset;
    if (MatchToken(it, TokenType::IDENTIFIER))
    {
        it++;
        if (MatchToken(it, TokenType::OPERATOR))
        {
            return parse_DeclList();
        }
        else
        {
            std::runtime_error("Expected ';' or declaration expression after identifier.");
        }
    }
    else
    {
        if (MatchToken(it, TokenType::OPERATOR, ";"))
            return nullptr;
        else
            std::runtime_error("Expected ';'.");
    }
    return nullptr;
}

std::shared_ptr<DeclList> Parser::parse_DeclList()
{
    std::string name = tokenslist[offset].name;
    offset++;
    if (MatchToken(TokenType::OPERATOR, "="))
    {
        offset++;
        std::shared_ptr<ExpressionNode> init = ExpectExpression();
        return std::make_shared<DeclList>(name, init);
    }
    else if (MatchToken(TokenType::OPERATOR, ";"))
        return std::make_shared<DeclList>(name, nullptr);
    return nullptr;
}

std::shared_ptr<FunctionDeclaration> Parser::parse_functiondeclaration()
{

    return nullptr;
}

/*****************
 *  Expressions  *
 *****************/

std::shared_ptr<Literal> Parser::parse_literal()
{
    std::string ret = tokenslist[offset].name;
    ++offset;
    return std::make_shared<Literal>(Literal(ret));
}