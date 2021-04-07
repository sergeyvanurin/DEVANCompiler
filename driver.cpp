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

void Driver::run() {
    SymbolTreeVisitor scope_visitor = SymbolTreeVisitor();
    scope_visitor.Visit(program);

    std::cout << "Symbol tree built\n";

    InterpreterVisitor interpreter;
    program->Accept(&interpreter);
}

