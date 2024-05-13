#pragma once
#include <string>
#include "Abstract Syntax Tree.hpp"

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
};

/***************************************
 *           Expressions.hpp           *
 *           UnaryExpression           *
 ***************************************/

struct UnaryExpression : ExpressionNode
{
    virtual ~UnaryExpression() = default;
};

struct PrefixExpression : UnaryExpression
{
    std::string op;
    std::shared_ptr<ExpressionNode> operand;
};

struct PostfixExpression : PrefixExpression
{
};

/***************************************
 *           Expressions.hpp           *
 *         FunctionExpression          *
 ***************************************/

struct FunctionExpression : ExpressionNode
{
    std::string function_name;
    std::vector<std::shared_ptr<ExpressionNode>> arguments;
};

/***************************************
 *           Expressions.hpp           *
 *            VariabelAcces            *
 ***************************************/

struct IdentifierNode : ExpressionNode
{
    std::string var_name;
};

/***************************************
 *           Expressions.hpp           *
 *               Literal               *
 ***************************************/

struct Literal : ExpressionNode
{
    std::string value;
};

/***************************************
 *           Expressions.hpp           *
 *             Assginment              *
 ***************************************/

struct AssignmentExpression : ExpressionNode
{
    std::shared_ptr<VariableDeclaration> var;
    std::shared_ptr<ExpressionNode> val;
};