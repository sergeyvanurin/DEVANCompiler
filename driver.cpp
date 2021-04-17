#include <Visitors/ExecuteVisitor.h>
#include "driver.hpp"

Driver::Driver(): scanner(*this), parser(scanner, *this), trace_parsing(false), trace_scanning(false) {
}

int Driver::parse(const std::string& filename)
{
    file = filename;
    std::ifstream in(filename);
    scanner.yyrestart(&in);
    loc.initialize(&file);
    parser.set_debug_level(trace_parsing);
    scanner.set_debug(trace_scanning);
    return parser();
}

void Driver::print_tree(const std::string& filename) const {
    PrintVisitor visitor(filename);
    program->Accept(&visitor);
}

int Driver::run() {
    SymbolTreeVisitor scope_visitor = SymbolTreeVisitor();
    try {
        scope_visitor.Visit(program);
    }
    catch (const std::runtime_error &e) {
        return 1;
    }

    std::cout << "Symbol tree built" << std::endl;

    ExecuteVisitor interpreter;
    program->Accept(&interpreter);
}

