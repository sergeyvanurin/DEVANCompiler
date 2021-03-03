#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "scanner.hpp"
#include "parser.hpp"


class Driver {
public:
    Driver();

    std::map<std::string, int> variables;

    std::vector<Scope*> scopes;
    int current_scope = 0;
    void add_scope();
    Scope* get_scope();
    void remove_scope();

    int parse(const std::string& filename);
    std::string file;
    bool trace_parsing;
    bool trace_scanning;
    yy::location loc;

    friend class Scanner;

    Scanner scanner;
    yy::parser parser;

};