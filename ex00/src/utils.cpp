#include "utils.hpp"
#include <string>
#include <climits>

static unsigned int countChar(const std::string& str, const char target) {
    unsigned int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        char c = str.at(i);
        if (c == target) {
            count++;
        }
    }
    return count;
}

bool ft_isChar(const std::string& literal)
{
    if (literal.length() != 1)
        return false;
    unsigned char c = static_cast<unsigned char>(literal.at(0));
    if (c > CHAR_MAX || isdigit(c))
            return false;
    return true;
}

bool ft_isInt(const std::string& literal)
{
    size_t i = 0;
    if (literal.at(0) == '+' || literal.at(0) == '-') {
        if (literal.length() == 1) {
            return false;
        }
        i++;
    }
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

bool ft_isFloat(const std::string& literal)
{
    if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    if (literal.at(literal.length() - 1) != 'f')
        return false;
    if (countChar(literal, '.') > 1)
        return false;
    if (countChar(literal, '-') > 1)
        return false;
    if (countChar(literal, '+') > 1)
        return false;
    size_t i = 0;
    if (literal.at(i) == '+' || literal.at(i) == '-') {
        i++;
    }
    for (; i < literal.length() - 1; i++)
    {
        if (literal.at(i) == '.')
            continue;
        else if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

bool ft_isDouble(const std::string& literal)
{
    if (literal == "inf" || literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    if (countChar(literal, '.') != 1)
        return false;
    if (countChar(literal, '-') > 1)
        return false;
    if (countChar(literal, '+') > 1)
        return false;
    size_t i = 0;
    if (literal.at(i) == '+' || literal.at(i) == '-') {
        i++;
    }
    for (; i < literal.length(); i++)
    {
        if (literal.at(i) == '.')
            continue;
        else if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}