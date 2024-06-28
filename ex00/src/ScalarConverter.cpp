#include "ScalarConverter.hpp"
#include <iomanip>

bool ScalarConverter::isImpossible(LiteralType type, const std::string& literal)
{
    try {
        if (type == INT_LITERAL) {
            std::stoi(literal);
        } else if (type == FLOAT_LITERAL) {
            std::stof(literal);
        } else if (type == DOUBLE_LITERAL) {
            std::stod(literal);
        }
    }
    catch(std::exception& e) {
        return true;
    }
    return false;
}

void ScalarConverter::printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    enum LiteralType literal_type = detectLiteralType(literal);
    if (isImpossible(literal_type, literal)) {
        printImpossible();
        return ;
    }
    switch (literal_type) {
        case (CHAR_LITERAL): {
            char c = literal[0];
            printChar(c);
            printInt(static_cast<int>(c));
            printFloat(static_cast<float>(c));
            printDouble(static_cast<double>(c));
            break ;
        }
        case (INT_LITERAL): {
            int v = std::stoi(literal);
            printChar(static_cast<char>(v));
            printInt(v);
            printFloat(static_cast<float>(v));
            printDouble(static_cast<double>(v));
            break ;
        }
        case (FLOAT_LITERAL): {
            float v = std::stof(literal);
            if (literal == "nanf") {
                std::cout << "char: impossible" << std::endl;
            } else {
                printChar(static_cast<char>(v));
            }
            if (literal == "nanf") {
                std::cout << "int: impossible" << std::endl;
            } else {
                printInt(static_cast<int>(v));
            }
            printFloat(v);
            printDouble(static_cast<double>(v));
            break ;
        }
        case (DOUBLE_LITERAL): {
            double v = std::stod(literal);
            if (literal == "nan") {
                std::cout << "char: impossible" << std::endl;
            } else {
                printChar(static_cast<char>(v));
            }
            if (literal == "nan") {
                std::cout << "int: impossible" << std::endl;
            } else {
                printInt(static_cast<int>(v));
            }
            printFloat(static_cast<float>(v));
            printDouble(v);
            break ;
        }
        default:
            std::cout << "no such type literal" << std::endl;
    }
}

void ScalarConverter::printChar(char c)
{
    std::cout << "char: ";
    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int v)
{
    std::cout << "int: " << v << std::endl;
}

void ScalarConverter::printFloat(float v)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << v << "f" << std::endl;
}

void ScalarConverter::printDouble(double v)
{
    std::cout << "double: " << v << std::endl;
}

LiteralType ScalarConverter::detectLiteralType(const std::string& literal)
{
    if (literal.length() == 0) {
        return NOSUCHTYPE_LITERAL;
    }
    if (literal.length() == 1
        && !std::isdigit(literal[0])) {
        return CHAR_LITERAL;
    }
    // You have to handle these pseudo literals as well (you know, for science): -inff, +inff, nanf
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return FLOAT_LITERAL;
    }
    // You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return DOUBLE_LITERAL;
    }

    // check float type
    if (literal[literal.length() - 1] == 'f') {
        return FLOAT_LITERAL;
    }

    // check double type
    if (literal.find('.') != std::string::npos)
        return DOUBLE_LITERAL;

    return INT_LITERAL;
}