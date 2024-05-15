#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include "token.hpp"
#include "AbstractSyntaxTree.hpp"

class Parser
{
public:
    void parse();
    Parser(std::vector<Token> &tokens) : tokenslist(tokens), offset(0){};

    /********************
     *     Service      *
     ********************/
    std::unordered_set<std::string> declOperators{
        "=",
        "+=",
        "-=",
        "*=",
        "/="};

    std::unordered_set<std::string> BuiltinTypes{
        "int",
        "void",
        "float",
        "bool",
        "char"};

    bool MatchToken(const TokenType &, const std::string & = "");
    bool MatchToken(const std::vector<Token>::iterator &, const TokenType &, const std::string & = "");
    std::vector<std::shared_ptr<ASTNode>> ASTresult;
    std::vector<Token> tokenslist;
    int offset;

    /********************
     *    Statements    *
     ********************/
    std::shared_ptr<StatementNode> ExpectStatement();
    std::shared_ptr<CompoundStatement> parse_compoundstatement();
    std::shared_ptr<DeclarationNode> parse_declarationstatement();
    std::shared_ptr<ExpressionStatement> parse_expressionstatement();
    std::shared_ptr<ControlStatement> parse_controlstatement();
    std::shared_ptr<ConditionalStatement> parse_conditionalstatement();
    std::shared_ptr<IterativeStatement> parse_iterativestatement();

    /********************
     *   Expressions    *
     ********************/
    std::shared_ptr<ExpressionNode> ExpectExpression();
    std::shared_ptr<BinaryExpression> parse_binaryexpression();
    std::shared_ptr<UnaryExpression> parse_unaryexpression();
    std::shared_ptr<FunctionExpression> parse_functionexpression();
    std::shared_ptr<IdentifierNode> parse_identifiernode();
    std::shared_ptr<Literal> parse_literal();
    std::shared_ptr<AssignmentExpression> parse_assignment();

    /********************
     *   Declarations   *
     ********************/
    std::shared_ptr<DeclarationNode> ExpectDeclaration();
    std::shared_ptr<VariableDeclaration> parse_variabledeclaration();
    std::shared_ptr<FunctionDeclaration> parse_functiondeclaration();
};