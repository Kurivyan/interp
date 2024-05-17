#pragma once
#include <string>
#include "AbstractSyntaxTree.hpp"

struct VariableDeclaration;

/***************************************
 *           Expressions.hpp           *
 *          BinaryExpression           *
 ***************************************/

struct BinaryExpression : public ExpressionNode
{
    std::string op;
    std::shared_ptr<ExpressionNode> operand_l;
    std::shared_ptr<ExpressionNode> operand_r;
    void accept(Visitor &);
};

/***************************************
 *           Expressions.hpp           *
 *           UnaryExpression           *
 ***************************************/

struct UnaryExpression : ExpressionNode
{
    std::string op;
    std::shared_ptr<ExpressionNode> operand;
    void accept(Visitor &);
};

struct PostfixExpression : UnaryExpression
{
    void accept(Visitor &);
};

/***************************************
 *           Expressions.hpp           *
 *         FunctionExpression          *
 ***************************************/

struct FunctionExpression : ExpressionNode
{
    std::string function_name;
    std::vector<std::shared_ptr<ExpressionNode>> arguments;
    void accept(Visitor &);
};

/***************************************
 *           Expressions.hpp           *
 *            VariabelAcces            *
 ***************************************/

struct IdentifierNode : ExpressionNode
{
    std::string var_name; // Variabel
    void accept(Visitor &);
};

/***************************************
 *           Expressions.hpp           *
 *               Literal               *
 ***************************************/

struct Literal : ExpressionNode
{
    Literal(const std::string &val) : value(val){};
    std::string value; // Constant Value
    void accept(Visitor &);
};

/***************************************
 *           Expressions.hpp           *
 *             Assginment              *
 ***************************************/

struct AssignmentExpression : ExpressionNode
{
    std::shared_ptr<ExpressionNode> var; // Identifier
    std::shared_ptr<ExpressionNode> val; // Value
    void accept(Visitor &);
};