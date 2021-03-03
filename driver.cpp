#include "driver.hpp"
#include "parser.hpp"

Driver::Driver(): scanner(*this), parser(scanner, *this), trace_parsing(false), trace_scanning(false) {}

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
