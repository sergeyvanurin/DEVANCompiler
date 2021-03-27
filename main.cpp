#include "driver.hpp"
#include "Visitors/PrintVisitor.h"

int main(int argc, char** argv)
{
    Driver d;
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <mini-java file>";
        return 0;
    }
    std::string filename(argv[1]);
    int error = d.parse(filename);
    if (!error) {
        if (argc == 3){
            d.print_tree(argv[2]);
        }
    }

} 