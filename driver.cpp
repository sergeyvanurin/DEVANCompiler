#include "driver.hpp"

Driver::Driver(): scanner(*this), parser(scanner, *this), trace_parsing(false), trace_scanning(false) {
    scopes.push_back(new Scope(current_scope, nullptr));
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

void Driver::add_scope() {
    scopes.push_back(new Scope(current_scope, current_scope != 0 ? scopes[current_scope - 1] : nullptr));
    current_scope++;
}
