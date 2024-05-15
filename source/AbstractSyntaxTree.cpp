#include "visitor.hpp"

/****************
 * Declarations *
 ****************/

void VariableDeclaration::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void FunctionDeclaration::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

/***************
 * Expressions *
 ***************/

void BinaryExpression::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void UnaryExpression::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void PostfixExpression::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void FunctionExpression::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void IdentifierNode::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void Literal::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void AssignmentExpression::accept(Visitor &visitor)
{
    visitor.visit(*this);
}