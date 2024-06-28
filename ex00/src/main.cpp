#include "ScalarConverter.hpp"
#include "ScalarConverter2.hpp"
#include "ScalarConverter3.hpp"
#include "Converter.hpp"
#include <iostream>

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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            ScalarConverter3::convert(literal);
            
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
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            ScalarConverter3::convert(literal);
            
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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            ScalarConverter3::convert(literal);
            
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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            ScalarConverter3::convert(literal);
            
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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            Converter c;
            c.setStr(literal);
            c.convert();
            std::cout << c;
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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            Converter c;
            c.setStr(literal);
            c.convert();
            std::cout << c;
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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            ScalarConverter3::convert(literal);
            
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
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            Converter c;
            c.setStr(literal);
            c.convert();
            std::cout << c;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    {
        std::string literal = "2147483648.0f";
        try {
            std::cout << "========= other test float over INT_MAX =========" << std::endl;
            std::cout << "========= my ==============" << std::endl;
            ScalarConverter::convert(literal);
            std::cout << "======== chatgpt ==========" << std::endl;
            ScalarConverter2::convert(literal);
            std::cout << "======== sample ===========" << std::endl;
            Converter c;
            c.setStr(literal);
            c.convert();
            std::cout << c;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }   
    return EXIT_SUCCESS;
}