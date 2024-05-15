#include <iostream>
#include <unordered_map>
#include <memory>
#include "lexer.hpp"
#include "parser.hpp"
#include "visitor.hpp"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Lexer lexer(argv[1]);
        lexer.tokenize();

        Parser parser(lexer.tokens);
        parser.parse();

        Printer printer;
        printer.print(parser.ASTresult[0]);
    }
    else
    {
        std::runtime_error("No input file provided.");
    }
    return 0;
}