#include "driver.hpp"
#include "Visitors/PrintVisitor.h"

int main(int argc, char** argv)
{
    Driver d;
    d.parse(argv[1]);
    d.print_tree();

} 