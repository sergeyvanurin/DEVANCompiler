#pragma once
#include <string>
#include <map>
#include <fstream>

#include "scanner.hpp"
#include "parser.hpp"


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

};