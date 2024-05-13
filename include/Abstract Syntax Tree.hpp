#pragma once
#include <vector>
#include <memory>

struct ASTNode
{
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