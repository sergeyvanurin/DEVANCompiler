#include "driver.hpp"
#include "Visitors/PrintVisitor.h"

int main(int argc, char** argv)
{
    Driver d;
    std::string filename(argv[1]);
    int error = d.parse(filename);
    if (!error) {
        d.print_tree();
    }
} 