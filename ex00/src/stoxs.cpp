#include "stoxs.hpp"
#include <stdexcept>
#include <sstream>

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
    std::stringstream ss(str);
    double result;
    ss >> result;
    if (ss.fail()) {
        // 変換が失敗した場合のエラーハンドリング
        throw std::invalid_argument("Invalid input string: " + str);
    }
    return result;
}