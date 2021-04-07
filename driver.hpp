#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "scanner.hpp"
#include "parser.hpp"
#include "Visitors/PrintVisitor.h"
#include "Visitors/InterpreterVisitor.h"


class Driver {
public:
    Driver();

    std::map<std::string, int> variables;

    int parse(const std::string& filename);
    std::string file;
    bool trace_parsing;
    bool trace_scanning;
    yy::location loc;

    friend class Scanner;

    Scanner scanner;
    yy::parser parser;

    Program* program;
    void print_tree(const std::string& filename) const;
    void run();

};