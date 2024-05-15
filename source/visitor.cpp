#include <iostream>
#include "visitor.hpp"
#include <cmath>

void Printer::print(const std::shared_ptr<ASTNode> &root)
{
    root->accept(*this);
    std::cout << std::endl;
    return;
}

virtual void Printer::visit(VariableDeclaration &root) { return; }
virtual void Printer::visit(FunctionDeclaration &root) { return; }

virtual void Printer::visit(DeclarationStatment &root) { return; }
virtual void Printer::visit(ExpressionNode &root) { return; }
virtual void Printer::visit(Continue &root) { return; }
virtual void Printer::visit(Break &root) { return; }
virtual void Printer::visit(Return &root) { return; }
virtual void Printer::visit(CompoundStatement &root) { return; }
virtual void Printer::visit(ifStatement &root) { return; }
virtual void Printer::visit(whileStatement &root) { return; }
virtual void Printer::visit(doWhileStatement &root) { return; }
virtual void Printer::visit(forStatement &root) { return; }

virtual void Printer::visit(BinaryExpression &root) { return; }
virtual void Printer::visit(PrefixExpression &root) { return; }
virtual void Printer::visit(PostfixExpression &root) { return; }
virtual void Printer::visit(FunctionExpression &root) { return; }
virtual void Printer::visit(IdentifierNode &root) { return; }
virtual void Printer::visit(Literal &root) { return; }
virtual void Printer::visit(AssignmentExpression &root) { return; }