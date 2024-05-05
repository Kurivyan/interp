#include <vector>
#include <memory>
#include "Statments.hpp"
#include "Declarations.hpp"
#include "Expressions.hpp"

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