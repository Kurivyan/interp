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
};

struct ExpressionNode : ASTNode
{
    virtual ~ExpressionNode() = default;
};

struct DeclarationNode : ASTNode
{
    virtual ~DeclarationNode() = default;
};

#include "Expressions.hpp"
#include "Declarations.hpp"
#include "Statments.hpp"