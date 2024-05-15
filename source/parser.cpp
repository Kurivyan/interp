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

bool Parser::MatchToken(const std::vector<Token>::iterator &it, const TokenType &type, const std::string &name)
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
            if (MatchToken(it, TokenType::OPERATOR, "=") || MatchToken(it, TokenType::OPERATOR, ";"))
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
    std::shared_ptr<VariableDeclaration> res;
    res->type = tokenslist[offset].name;
    offset++;
    res->name = tokenslist[offset].name;
    offset++;
    if (MatchToken(TokenType::OPERATOR, ";"))
        return res;
    return nullptr;
}

std::shared_ptr<FunctionDeclaration> Parser::parse_functiondeclaration()
{
    return nullptr;
}