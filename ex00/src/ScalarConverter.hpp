#ifndef SCALARCONVERTER_HPP 
# define SCALARCONVERTER_HPP 
# include <iostream>
# include <climits>
# include <string>

enum LiteralType {
  CHAR_LITERAL,
  INT_LITERAL,
  FLOAT_LITERAL,
  DOUBLE_LITERAL,
  NOSUCHTYPE_LITERAL
};

class ScalarConverter {
private:
    // This class is static class. we need not implement constructor.
    ScalarConverter();

    // member functions
    static LiteralType detectLiteralType(const std::string& literal);
    static bool isImpossible(LiteralType type, const std::string& literal);
    static void printChar(char c);
    static void printInt(int v);
    static void printFloat(float v);
    static void printDouble(double v);
    static void printImpossible();
public:
    // static functions
    static void convert(const std::string& target);
};

#endif