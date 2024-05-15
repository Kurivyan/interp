#include <iostream>
#include <unordered_map>
#include <memory>
#include "lexer.hpp"
#include "parser.hpp"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Lexer lexer(argv[1]);
        lexer.tokenize();

        Parser parser(lexer.tokens);
        parser.parse();
    }
    else
    {
        std::runtime_error("No input file provided.");
    }
    return 0;
}