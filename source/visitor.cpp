#include <iostream>
#include <cmath>
#include "visitor.hpp"

void Printer::print(const std::shared_ptr<ASTNode> &root)
{
    root->accept(*this);
    std::cout << std::endl;
    return;
}

void Printer::visit(VariableDeclaration &root)
{
    std::cout << root.type << " " << root.name << " " << ";\n";
    return;
}
void Printer::visit(FunctionDeclaration &root) { return; }

void Printer::visit(DeclarationStatment &root) { return; }
void Printer::visit(ExpressionNode &root) { return; }
void Printer::visit(Continue &root) { return; }
void Printer::visit(Break &root) { return; }
void Printer::visit(Return &root) { return; }
void Printer::visit(CompoundStatement &root) { return; }
void Printer::visit(ifStatement &root) { return; }
void Printer::visit(whileStatement &root) { return; }
void Printer::visit(doWhileStatement &root) { return; }
void Printer::visit(forStatement &root) { return; }

void Printer::visit(BinaryExpression &root) { return; }
void Printer::visit(UnaryExpression &root) { return; }
void Printer::visit(PostfixExpression &root) { return; }
void Printer::visit(FunctionExpression &root) { return; }
void Printer::visit(IdentifierNode &root) { return; }
void Printer::visit(Literal &root) { return; }
void Printer::visit(AssignmentExpression &root) { return; }