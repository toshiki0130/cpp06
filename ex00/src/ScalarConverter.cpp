#include "ScalarConverter.hpp"
#include "stoxs.hpp"
#include <iomanip>

bool ScalarConverter::isImpossible(LiteralType type, const std::string& literal)
{
    try {
        if (type == INT_LITERAL) {
            ft_stoi(literal);
        } else if (type == FLOAT_LITERAL) {
            ft_stof(literal);
        } else if (type == DOUBLE_LITERAL) {
            ft_stod(literal);
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
    if (literal_type == NOSUCHTYPE_LITERAL || isImpossible(literal_type, literal)) {
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
            int v = ft_stoi(literal);
            if (v < CHAR_MIN || v > CHAR_MAX) {
                std::cout << "char: impossible" << std::endl;
            } else {
                printChar(static_cast<char>(v));
            }
            printInt(v);
            printFloat(static_cast<float>(v));
            printDouble(static_cast<double>(v));
            break ;
        }
        case (FLOAT_LITERAL): {
            float v = ft_stof(literal);
            if (literal == "nanf" || v < CHAR_MIN || v > CHAR_MAX) {
                std::cout << "char: impossible" << std::endl;
            } else {
                printChar(static_cast<char>(v));
            }
            if (literal == "nanf" || static_cast<double>(v) < INT_MIN || static_cast<double>(v) > INT_MAX) {
                std::cout << "int: impossible" << std::endl;
            } else {
                printInt(static_cast<int>(v));
            }
            printFloat(v);
            printDouble(static_cast<double>(v));
            break ;
        }
        case (DOUBLE_LITERAL): {
            double v = ft_stod(literal);
            if (literal == "nan" || v < CHAR_MIN || v > CHAR_MAX) {
                std::cout << "char: impossible" << std::endl;
            } else {
                printChar(static_cast<char>(v));
            }
            if (literal == "nan" || v < INT_MIN || v > INT_MAX) {
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
    if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return FLOAT_LITERAL;
    }
    // You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan
    if (literal == "inf"|| literal == "-inf" || literal == "+inf" || literal == "nan") {
        return DOUBLE_LITERAL;
    }

    // check float type
    if (literal[literal.length() - 1] == 'f') {
        return FLOAT_LITERAL;
    }

    // check double type
    if (literal.find('.') != std::string::npos)
        return DOUBLE_LITERAL;

    // check int type
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-') {
        if (literal.length() == 1) {
            return NOSUCHTYPE_LITERAL;
        }
        i++;
    }
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) {
            return NOSUCHTYPE_LITERAL;
        }
    }
    return INT_LITERAL;
}