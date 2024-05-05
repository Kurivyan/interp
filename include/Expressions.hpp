#pragma once
#include "Abstract Syntax Tree.hpp"

/***************************************
 *           Expressions.hpp           *
 *          BinaryExpression           *
 ***************************************/

struct BinaryExpression : ExpressionNode
{
    std::string operator;
    std::shared_ptr<ExpressionNode> operand_l;
    std::shared_ptr<ExpressionNode> operand_r;
};

/***************************************
 *           Expressions.hpp           *
 *           UnaryExpression           *
 ***************************************/

struct UnaryExpression : ExpressionNode
{
    std::string operator;
    std::shared_ptr<ExpressionNode> operand;
};

/***************************************
 *           Expressions.hpp           *
 *         FunctionExpression          *
 ***************************************/

struct FunctionExpression : ExpressionNode
{
    std::string function_name;
    std::vector<std::shared_ptr<VariableDeclaration>> arguments;
};

/***************************************
 *           Expressions.hpp           *
 *            VariabelAcces            *
 ***************************************/

struct VariableAcces : ExpressionNode
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