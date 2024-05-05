#include <vector>
#include <memory>
#include "token.hpp"
#include "Abstract Syntax Tree.hpp"

class Parser
{
public:
    Parser(std::vector<Token> build_list);
    std::shared_ptr<ASTNode> parse();

private:
    /********************
     *    Statements    *
     ********************/
    std::shared_ptr<ASTNode> parse_compoundstatement();
    std::shared_ptr<ASTNode> parse_declarationstatement();
    std::shared_ptr<ASTNode> parse_expressionstatement();
    std::shared_ptr<ASTNode> parse_controlstatement();
    std::shared_ptr<ASTNode> parse_conditionalstatement();
    std::shared_ptr<ASTNode> parse_iterativestatement();

    /********************
     *   Expressions    *
     ********************/

    std::shared_ptr<ASTNode> parse_binaryexpression();
    std::shared_ptr<ASTNode> parse_unaryexpression();
    std::shared_ptr<ASTNode> parse_functionexpression();
    std::shared_ptr<ASTNode> parse_variabelacces();
    std::shared_ptr<ASTNode> parse_literal();

    /********************
     *   Declarations   *
     ********************/

    std::shared_ptr<ASTNode> parse_variabledeclaration();
    std::shared_ptr<ASTNode> parse_functiondeclaration();

    std::vector<Token> list;
}