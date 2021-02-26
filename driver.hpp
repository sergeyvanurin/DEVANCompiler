#pragma once
#include <string>
#include <map>
#include <fstream>

#include "scanner.hpp"
#include "parser.h"


class Driver {
public:
    Driver();

    std::map<std::string, int> variables;

    int parse(const std::string& filename);

    friend class Scanner;

    Scanner scanner;
    yy::parser parser;

};