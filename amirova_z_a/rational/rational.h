// rational.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

const std::runtime_error zero_division_error("Division by Zero");
const std::runtime_error bad_formatting_error("Bad Format");

class rational {
public:
    rational() = default;
    explicit rational(int64_t);
    rational(const int64_t numerator, const int64_t denumerator) {
        num = numerator;
        denum = denumerator;
        if (denum == 0) {
            throw zero_division_error;
        }
        Modify();
        Format();
    }

    int64_t GetNum() const {
        return num;
    }
    int64_t GetDenum() const {
        return denum;
    }

    rational& operator=(rational& lhs) = default;
    rational& operator+=(const rational& lhs);
    rational& operator-=(const rational& lhs);
    rational& operator*=(const rational& lhs);
    rational& operator/=(const rational& lhs);
    rational& operator++();
    rational operator++(int);
    rational& operator--();
    rational operator--(int);


    bool operator==(const rational& lhs);
    bool operator!=(const rational& lhs);
    bool operator>(const rational& lhs);
    bool operator<(const rational& lhs);
    bool operator>=(const rational& lhs);
    bool operator<=(const rational& lhs);

    rational operator-() const {
        return {
            (-1) * GetNum(), GetNum()
        };
    }

    std::istream& ReadFrom(std::istream& in) {
        char slash{ 0 };
        int64_t nmrtr{ 0 };
        int64_t dnmrtr{ 0 };

        if (!in.good()) {
            return in;
        }
        in >> nmrtr >> slash >> dnmrtr;
        if (slash != slesh || dnmrtr < 0) {
            throw bad_formatting_error;
            in.setstate(in.failbit);
        }
        if (dnmrtr == 0) {
            throw zero_division_error;
            in.setstate(in.failbit);
        }
        num = nmrtr;
        denum = dnmrtr;
        return in;
        Modify();
        Format();
    }
    std::ostream& WriteTo(std::ostream& out) const {
        out << num << slesh << denum;
        return out;
    }

    ~rational() = default;

private:
    int64_t num{ 0 };
    int64_t denum{ 1 };
    static const char slesh{ '/' };

    static int64_t GCD(int64_t lhs_, int64_t rhs_) {
        if (lhs_ == 0) {
            return rhs_;
        }
        else if (rhs_ == 0) {
            return lhs_;
        }
        else {
            return GCD(std::max(lhs_, rhs_) % std::min(lhs_, rhs_), std::min(lhs_, rhs_));
        }
    }

    void Modify() {
        int64_t gcd = GCD(num, denum);
        num /= gcd;
        denum /= gcd;
    }

    void Format() {
        if (num * denum < 0) {
            denum = std::abs(denum);
            num = -std::abs(num);
        }
    }
};

// TODO: Reference additional headers your program requires here.
