#include <iostream>
#include<sstream>

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
