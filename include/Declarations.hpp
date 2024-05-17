#pragma once
#include "AbstractSyntaxTree.hpp"

struct CompoundStatement;

struct DeclList
{
    DeclList(const std::string &name, const std::shared_ptr<ExpressionNode> &list) : declarator(name), initList(list){};
    std::string declarator;
    std::shared_ptr<ExpressionNode> initList;
    void accept(Visitor &);
};

struct VariableDeclaration : DeclarationNode
{
    VariableDeclaration(const std::string &type, std::vector<std::shared_ptr<DeclList>> &declist)
        : type(type), declaratorlist(declist){};
    std::string type;
    std::vector<std::shared_ptr<DeclList>> declaratorlist;
    void accept(Visitor &);
};

struct FunctionDeclaration : DeclarationNode
{
    std::string return_type;
    std::string name;
    std::vector<std::shared_ptr<DeclarationNode>> arguments;
    std::shared_ptr<CompoundStatement> body;
    void accept(Visitor &);
};