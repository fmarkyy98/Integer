#ifndef INTEGER
#define INTEGER

#include <string>
#include <iostream>

class Integer {
public:
    Integer(int value = 0);
    Integer(std::string value);

    Integer& operator=(const Integer& that) { value_ = that.value_; return *this;}

    friend Integer operator+(const Integer& lhs, const Integer& rhs);
    friend Integer operator*(const Integer& lhs, const Integer& rhs);

    friend bool operator==(const Integer& lhs, const Integer& rhs) { return lhs.value_ == rhs.value_; } 
    friend bool operator!=(const Integer& lhs, const Integer& rhs) { return !(lhs == rhs); }

    friend bool operator<(const Integer& lhs, const Integer& rhs);
    friend bool operator<=(const Integer& lhs, const Integer& rhs) { return lhs < rhs || lhs == rhs; }
    friend bool operator>(const Integer& lhs, const Integer& rhs) { return  !(lhs < rhs) && !(lhs == rhs); }
    friend bool operator>=(const Integer& lhs, const Integer& rhs) { return !(lhs < rhs); }

    friend std::ostream& operator<<(std::ostream& os, const Integer& integer);

private:
    bool is_numeric(const std::string& value);
    friend std::string str_add(const std::string& lhs, const std::string& rhs); 
    friend std::string str_mul(const std::string& lhs, const std::string& rhs);

private:
    std::string value_;

    static constexpr short int char_0_asci_ = '0';
};



#endif //INTEGER