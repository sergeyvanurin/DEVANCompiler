#include "driver.hpp"

Driver::Driver(): scanner(*this), parser(scanner, *this), trace_parsing(false), trace_scanning(false) {
    scopes.push_back(new Scope(current_scope, nullptr, loc));
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
    scopes.push_back(new Scope(current_scope, current_scope != 0 ? scopes[current_scope - 1] : nullptr, loc));
    current_scope++;
}

Scope *Driver::get_scope() {
    return this->scopes[current_scope];
}

void Driver::remove_scope() {
    scopes.pop_back();
    current_scope--;
}

void Driver::print_tree() {
    PrintVisitor visitor;
    program->Accept(&visitor);
}
