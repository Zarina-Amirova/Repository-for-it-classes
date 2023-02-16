#include <iostream>
#include<sstream>

const std::runtime_error zero_division_error ("Division by Zero");
const std::runtime_error bad_formatting_error("Bad Format");


class rational {
public:
    rational() = default;
    explicit rational(int64_t);
    rational(const int64_t numerator,const int64_t denumerator) {
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
    bool operator<=(const rational & lhs);

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
rational& rational::operator+=(const rational& lhs) {
    int64_t bothdenum = lhs.GetDenum() * denum;
    num = num * (bothdenum / denum) + lhs.num * (bothdenum / lhs.denum);
    denum = bothdenum;
    Modify();
    Format();
    return *this;
}

rational& rational::operator-=(const rational& lhs) {
    *this += -lhs;
    return *this;
}

rational& rational::operator*=(const rational& lhs) {
    num *= lhs.num;
    denum *= lhs.denum;
    return *this;
}

rational& rational::operator/=(const rational& lhs) {
    num *= lhs.denum;
    denum *= lhs.num;
    Format();
    return *this;
}


rational operator-(const rational& lhs_left, const rational& lhs_right) {
    rational temp = lhs_left;
    temp -= lhs_right;
    return temp;
}
rational operator+(const rational& lhs_left, const rational& lhs_right) {
    rational temp = lhs_left;
    temp += lhs_right;
    return temp;
}
rational operator*(const rational& lhs_left, const rational& lhs_right) {
    rational temp = lhs_left;
    temp *= lhs_right;
    return temp;
}
rational operator/(const rational& lhs_left, const rational& lhs_right) {
    rational temp = lhs_left;
    temp /= lhs_right;
    return temp;
}

rational& rational::operator++() {
    *this += rational(1, 1);
    return *this;
}

rational rational::operator++(int) {
    rational temp = *this;
    this->operator++();
    return temp;
}

rational& rational::operator--() {
    *this -= rational(1, 1);
    return *this;
}

rational rational::operator--(int) {
    rational temp = *this;
    this->operator--();
    return temp;
}
//have problems with bool type, don't know solution
bool rational::operator==(const rational& lhs) {
        return (denum == lhs.num && num == lhs.denum );
    }

bool rational::operator!=(const rational& lhs) {
    return(!(*this == lhs));
}
bool rational::operator>(const rational& lhs) {
    return (num * lhs.GetNum() > denum * lhs.GetDenum());
}
bool rational::operator<(const rational& lhs) {
    return (num * lhs.GetNum() < denum * lhs.GetDenum());
}
bool rational::operator>=(const rational& lhs) {
    return!(*this < lhs);
}
bool rational::operator<=(const rational& lhs) {
    return!(*this > lhs);
}

std::istream& operator>>(std::istream& in, rational& drob) {
    return(drob.ReadFrom(in));
}

std::ostream& operator<<(std::ostream& out, const rational& drob) {
    return(drob.WriteTo(out));
}

int main() {
    rational a{ 1,2 };
    rational b{ 1,3 };
    std::cout << a << ' ' << '+' << ' ' << b << ' ' << '=' << ' ' << a + b << '\n';
    std::cout << a << ' ' << '-' << ' ' << b << ' ' << '=' << ' ' << a - b << '\n';
    std::cout << a << ' ' << '*' << ' ' << b << ' ' << '=' << ' ' << a * b << '\n';
    std::cout << a << ' ' << '/' << ' ' << b << ' ' << '=' << ' ' << a / b << '\n';
}
