#include "driver.hpp"

Driver::Driver(): scanner(*this), parser(scanner, *this) {}

int Driver::parse(const std::string& filename)
{
    std::ifstream in(filename);
    scanner.yyrestart(&in);
    return parser();
}
