#include "stoxs.hpp"
#include <stdexcept>
#include <sstream>
#include <limits> // For quiet_NaN()

int ft_stoi(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    if (ss.fail()) {
        // 変換が失敗した場合のエラーハンドリング
        throw std::invalid_argument("Invalid input string: " + str);
    }
    return result;
}

float ft_stof(const std::string& str) {
    if (str == "nanf") {
        return std::numeric_limits<float>::quiet_NaN();
    }
    // "inff"のチェック
    if (str == "inff" || str == "+inff") {
        return std::numeric_limits<float>::infinity();
    }
    if (str == "-inff") {
        return -std::numeric_limits<float>::infinity();
    }
    std::stringstream ss(str);
    float result;
    ss >> result;
    if (ss.fail()) {
        // 変換が失敗した場合のエラーハンドリング
        throw std::invalid_argument("Invalid input string: " + str);
    }
    return result;
}

double ft_stod(const std::string& str) {
    if (str == "nan") {
        return std::numeric_limits<double>::quiet_NaN();
    }
    // "inf"のチェック
    if (str == "inf" || str == "+inf") {
        return std::numeric_limits<double>::infinity();
    }
    if (str == "-inf") {
        return -std::numeric_limits<double>::infinity();
    }
    std::stringstream ss(str);
    double result;
    ss >> result;
    if (ss.fail()) {
        // 変換が失敗した場合のエラーハンドリング
        throw std::invalid_argument("Invalid input string: " + str);
    }
    return result;
}