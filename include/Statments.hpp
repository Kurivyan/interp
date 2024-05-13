#pragma once
#include "Abstract Syntax Tree.hpp"

struct ExpressionNode;
struct DeclarationNode;

/*************************************
 *           Statments.hpp           *
 *       DeclarationStatement        *
 *************************************/

struct DeclarationStatment : StatementNode
{
    std::shared_ptr<VariableDeclaration> expression;
};

/*************************************
 *           Statments.hpp           *
 *        ExpressionStatement        *
 *************************************/

struct ExpressionStatement : StatementNode
{
    std::shared_ptr<ExpressionNode> expression;
};

/*************************************
 *           Statments.hpp           *
 *         ControlStatement          *
 *************************************/

struct ControlStatement : StatementNode
{
    virtual ~ControlStatement() = default;
};

struct Continue : ControlStatement
{
};

struct Break : ControlStatement
{
};

struct Return : ControlStatement
{
    std::shared_ptr<ExpressionNode> return_value;
};

/*************************************
 *           Statments.hpp           *
 *         CompoundStatement         *
 *************************************/

struct CompoundStatement : StatementNode
{
    std::vector<std::shared_ptr<StatementNode>> body;
};

/*************************************
 *           Statments.hpp           *
 *       ConditionalStatement        *
 *************************************/

struct ConditionalStatement : StatementNode
{
    virtual ~ConditionalStatement() = default;
};

struct ifStatement : ConditionalStatement
{
    std::shared_ptr<ExpressionNode> condition;
    std::shared_ptr<StatementNode> body;
    std::shared_ptr<StatementNode> else_body;
};

/*************************************
 *           Statments.hpp           *
 *        IterativeStatement         *
 *************************************/

struct IterativeStatement : StatementNode
{
    virtual ~IterativeStatement() = default;
};

struct whileStatement : IterativeStatement
{
    std::shared_ptr<ExpressionNode> condition;
    std::shared_ptr<StatementNode> body;
};

struct doWhileStatement : IterativeStatement
{
    std::shared_ptr<ExpressionNode> condition;
    std::shared_ptr<StatementNode> body;
};

struct forStatement : IterativeStatement
{
    std::vector<std::shared_ptr<ExpressionNode>> conditions;
    std::shared_ptr<StatementNode> body;
};