#include "Integer.h"
#include <sstream>

std::string str_add(const std::string& lhs, const std::string& rhs);
std::string str_mul(const std::string& lhs, const std::string& rhs);

Integer::Integer(int value) {
    std::stringstream ss;
    ss << value;
    ss >> value_;
}

Integer::Integer(std::string value) {
    if (!is_numeric(value)) {
        std::cerr << "\n[-Wformat] Invalid number format given.\n"
                     "Value inicialized to 0.\n";
        value_ = "0";
    } else {
        value_ = value;
    }
}

Integer operator+(const Integer& lhs, const Integer& rhs) {
    return Integer(str_add(lhs.value_, rhs.value_));
}

Integer operator*(const Integer& lhs, const Integer& rhs) {
    return Integer(str_mul(lhs.value_, rhs.value_));
}

bool operator<(const Integer& lhs, const Integer& rhs) {
    int n = lhs.value_.length();
    int m = rhs.value_.length();
    if (n == m) {
        for (int i = 0; i < n; ++i) {
            if (lhs.value_[i] == rhs.value_[i])
                continue;
            return lhs.value_[i] < rhs.value_[i];
        }
        return false;
    }
    return n < m;
}

 std::ostream& operator<<(std::ostream& os, const Integer& integer) {
     os << integer.value_;
     return os;
}

 bool Integer::is_numeric(const std::string& value) {
    for (auto c : value) 
        if (!isdigit(c)) 
            return false;
    return true;
}

std::string str_add(const std::string& lhs, const std::string& rhs) {
     std::string result = "";
    short int rest = 0;
    
    int n = lhs.length();
    int m = rhs.length();

    for (int i = 1; i <= std::min(n, m); ++i) {
        short int x = lhs[n - i] - Integer::char_0_asci_;
        short int y = rhs[m - i] - Integer::char_0_asci_;
        rest = x + y + rest;
        result = (char)(rest % 10 + Integer::char_0_asci_) + result;
        rest /= 10;
    }
    for (int i = std::min(n, m) + 1; i <= n; ++i) {
        short int x = lhs[n - i] - Integer::char_0_asci_;
        rest = x + rest;
        result = (char)(rest % 10 + Integer::char_0_asci_) + result;
        rest /= 10;
    }
    for (int i = std::min(n, m) + 1; i <= m; ++i) {
        short int y = rhs[m - i] - Integer::char_0_asci_;
        rest = y + rest;
        result = (char)(rest % 10 + Integer::char_0_asci_) + result;
        rest /= 10;
    }
    if (rest != 0)
        result = (char)(rest % 10 + Integer::char_0_asci_) + result;

    return result;
}

std::string str_mul(const std::string& lhs, const std::string& rhs) {
    std::string result = "";

    int n = lhs.length();
    int m = rhs.length();
   
    for (int i = 1; i <= n; ++i) {
        std::string partial_result = "";
        short int rest = 0;

        for (int j = 1; j <= m; ++j) {
            short int x = lhs[n - i] - Integer::char_0_asci_;
            short int y = rhs[m - j] - Integer::char_0_asci_;

            rest = x * y + rest;
            partial_result = (char)(rest % 10 + Integer::char_0_asci_) + partial_result;
            rest /= 10;
        }
        for (int j = 1; j < i; ++j) {
            partial_result += "0";
        }
        if (rest != 0)
            partial_result = (char)(rest % 10 + Integer::char_0_asci_) + partial_result;

        result = str_add(result, partial_result);
    }
    return result;
}