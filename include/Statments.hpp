#pragma once
#include "AbstractSyntaxTree.hpp"

struct ExpressionNode;
struct DeclarationNode;

/*************************************
 *           Statments.hpp           *
 *       DeclarationStatement        *
 *************************************/

struct DeclarationStatment : StatementNode
{
    std::shared_ptr<DeclarationNode> expression;
    void accept(Visitor &);
};

/*************************************
 *           Statments.hpp           *
 *        ExpressionStatement        *
 *************************************/

struct ExpressionStatement : StatementNode
{
    std::shared_ptr<ExpressionNode> expression;
    void accept(Visitor &);
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
    void accept(Visitor &);
};

struct Break : ControlStatement
{
    void accept(Visitor &);
};

struct Return : ControlStatement
{
    std::shared_ptr<ExpressionNode> return_value;
    void accept(Visitor &);
};

/*************************************
 *           Statments.hpp           *
 *         CompoundStatement         *
 *************************************/

struct CompoundStatement : StatementNode
{
    std::vector<std::shared_ptr<StatementNode>> body;
    void accept(Visitor &);
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
    void accept(Visitor &);
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
    void accept(Visitor &);
};

struct doWhileStatement : IterativeStatement
{
    std::shared_ptr<ExpressionNode> condition;
    std::shared_ptr<StatementNode> body;
    void accept(Visitor &);
};

struct forStatement : IterativeStatement
{
    std::vector<std::shared_ptr<ExpressionNode>> conditions;
    std::shared_ptr<StatementNode> body;
    void accept(Visitor &);
};