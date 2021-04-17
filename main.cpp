#include "driver.hpp"
#include "Visitors/PrintVisitor.h"
#include "Visitors/InterpreterVisitor.h"

int main(int argc, char** argv)
{
    Driver d;
    int error_code = 0;
    if (argc == 1) {
        std::cerr << "Usage: " << argv[0] << " <mini-java file> <output file>" ;
        return 0;
    }
    std::string filename(argv[1]);
    int error = d.parse(filename);
    if (!error) {
        if (argc == 3){
            d.print_tree(argv[2]);
        }
        error_code = d.run();
    }
    return error_code;
} 