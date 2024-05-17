#pragma once
#include "AbstractSyntaxTree.hpp"
#include "Declarations.hpp"
#include "Expressions.hpp"
#include "Statments.hpp"

struct Visitor
{
    virtual void visit(VariableDeclaration &) = 0;
    virtual void visit(DeclList &) = 0;
    virtual void visit(FunctionDeclaration &) = 0;

    virtual void visit(DeclarationStatment &) = 0;
    virtual void visit(ExpressionNode &) = 0;
    virtual void visit(Continue &) = 0;
    virtual void visit(Break &) = 0;
    virtual void visit(Return &) = 0;
    virtual void visit(CompoundStatement &) = 0;
    virtual void visit(ifStatement &) = 0;
    virtual void visit(whileStatement &) = 0;
    virtual void visit(doWhileStatement &) = 0;
    virtual void visit(forStatement &) = 0;

    virtual void visit(BinaryExpression &) = 0;
    virtual void visit(UnaryExpression &) = 0;
    virtual void visit(PostfixExpression &) = 0;
    virtual void visit(FunctionExpression &) = 0;
    virtual void visit(IdentifierNode &) = 0;
    virtual void visit(Literal &) = 0;
    virtual void visit(AssignmentExpression &) = 0;
};

struct Printer : Visitor
{
    void print(const std::shared_ptr<ASTNode> &);

    virtual void visit(VariableDeclaration &);
    virtual void visit(DeclList &);
    virtual void visit(FunctionDeclaration &);

    virtual void visit(DeclarationStatment &);
    virtual void visit(ExpressionNode &);
    virtual void visit(Continue &);
    virtual void visit(Break &);
    virtual void visit(Return &);
    virtual void visit(CompoundStatement &);
    virtual void visit(ifStatement &);
    virtual void visit(whileStatement &);
    virtual void visit(doWhileStatement &);
    virtual void visit(forStatement &);

    virtual void visit(BinaryExpression &);
    virtual void visit(UnaryExpression &);
    virtual void visit(PostfixExpression &);
    virtual void visit(FunctionExpression &);
    virtual void visit(IdentifierNode &);
    virtual void visit(Literal &);
    virtual void visit(AssignmentExpression &);
};