#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    {
        std::string literal = "0";
        try {
            std::cout << "========= subject 0=========" << std::endl;
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: 0" << std::endl;
            std::cout << "float: 0.0f" << std::endl;
            std::cout << "double: 0.0" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "";
        try {
            std::cout << "========= subject '' =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "\n";
        try {
            std::cout << "========= subject \\n =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "nan";
        try {
            std::cout << "========= subject nan =========" << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
            std::cout << "======== chatgpt ==========" << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "42.0f";
        try {
            std::cout << "========= subject 42.0f =========" << std::endl;
            std::cout << "char: '*'" << std::endl;
            std::cout << "int: 42" << std::endl;
            std::cout << "float: 42.0f" << std::endl;
            std::cout << "double: 42.0" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "nanf";
        try {
            std::cout << "========= other test nanf =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "2147483647";
        try {
            std::cout << "========= other test INT_MAX =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "2147483648";
        try {
            std::cout << "========= other test INT_MAX+1 =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "-2147483648";
        try {
            std::cout << "========= other test INT_MIN =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "-2147483649";
        try {
            std::cout << "========= other test INT_MIN-1 =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "abc";
        try {
            std::cout << "========= other test: abc =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "abc.0f";
        try {
            std::cout << "========= other test: abc =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    return EXIT_SUCCESS;
}