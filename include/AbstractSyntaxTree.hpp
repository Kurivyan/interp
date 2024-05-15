#pragma once
#include <vector>
#include <memory>
#include <optional>

struct Visitor;

struct ASTNode
{
    virtual void accept(Visitor &) = 0;
    virtual ~ASTNode() = default;
};

struct StatementNode : ASTNode
{
    virtual ~StatementNode() = default;
    virtual void accept(Visitor &) = 0;
};

struct ExpressionNode : ASTNode
{
    virtual ~ExpressionNode() = default;
    virtual void accept(Visitor &) = 0;
};

struct DeclarationNode : ASTNode
{
    virtual ~DeclarationNode() = default;
    virtual void accept(Visitor &) = 0;
};

#include "Expressions.hpp"
#include "Declarations.hpp"
#include "Statments.hpp"