#include "ScalarConverter.hpp"
#include "stoxs.hpp"
#include "utils.hpp"
#include <iomanip>

// orthodox canonical form
ScalarConverter::ScalarConverter()
{};

ScalarConverter::ScalarConverter(const ScalarConverter&)
{};

ScalarConverter::~ScalarConverter()
{};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
};

// member functions
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
        throw std::invalid_argument("Invaid literal");
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

    if (ft_isChar(literal))
        return CHAR_LITERAL; 
    
    if (ft_isFloat(literal))
        return FLOAT_LITERAL;

    if (ft_isDouble(literal))
        return DOUBLE_LITERAL;
    
    // check int type
    if (ft_isInt(literal))
        return INT_LITERAL;

    return NOSUCHTYPE_LITERAL;
}