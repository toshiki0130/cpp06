#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <put string for exchanging to data type(char/int/float/double)>"
              << std::endl;
    return EXIT_FAILURE;
    }
    try {
        ScalarConverter::convert(argv[1]);
        return EXIT_SUCCESS;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}