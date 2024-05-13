#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "token.hpp"
#include "Abstract Syntax Tree.hpp"

class Parser
{
public:
    void parse();
    Parser(std::vector<Token> &tokens) : tokenslist(tokens){};

private:
    /********************
     *     Service      *
     ********************/

    bool MatchToken(const TokenType &, const std::string &);
    std::vector<std::shared_ptr<ASTNode>> ASTresult;
    std::vector<Token> tokenslist;
    int offset;

    /********************
     *    Statements    *
     ********************/
    std::shared_ptr<ASTNode> parse_compoundstatement();
    std::shared_ptr<ASTNode> parse_declarationstatement();
    std::shared_ptr<ASTNode> parse_expressionstatement();
    std::shared_ptr<ASTNode> parse_controlstatement();
    std::shared_ptr<ASTNode> parse_conditionalstatement();
    std::shared_ptr<ASTNode> parse_iterativestatement();

    /********************
     *   Expressions    *
     ********************/
    std::shared_ptr<ASTNode> parse_binaryexpression();
    std::shared_ptr<ASTNode> parse_unaryexpression();
    std::shared_ptr<ASTNode> parse_functionexpression();
    std::shared_ptr<ASTNode> parse_identifiernode();
    std::shared_ptr<ASTNode> parse_literal();
    std::shared_ptr<ASTNode> parse_assignment();

    /********************
     *   Declarations   *
     ********************/
    std::shared_ptr<ASTNode> parse_variabledeclaration();
    std::shared_ptr<ASTNode> parse_functiondeclaration();
};