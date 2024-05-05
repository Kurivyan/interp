#pragma once
#include "Abstract Syntax Tree.hpp"

struct VariableDeclaration : DeclarationNode
{
    std::string type;
    std::string name;
    std::shared_ptr<ExpressionNode> initializer;
};

struct FunctionDeclaration : DeclarationNode
{
    std::string return_type;
    std::string name;
    std::vector<std::shared_ptr<VariableDeclaration>> arguments;
    std::shared_ptr<CompoundStatement> body;
};