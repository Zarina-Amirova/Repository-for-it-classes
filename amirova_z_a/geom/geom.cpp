#include <iostream>
#include <cmath>
#include "geom.h"


Vector_Dec operator +(const Vector_Dec& value, const Vector_Dec& value_2) {
	return { value.x + value_2.x, value.y + value_2.y };
}
Vector_Dec operator -(const Vector_Dec& value_2, const Vector_Dec& value) {
	return { value_2.x - value.x, value_2.y - value.y };
}

Vector_Dec operator *(const Vector_Dec& value, double num) {
	return { value.x * num, value.y * num };
}

Vector_Dec operator *(double num, const Vector_Dec& value) {
	return { num * value.x, num * value.y };
}

double operator*(const Vector_Dec& value_1, const Vector_Dec& value_2) {
	return value_1.x * value_2.x + value_1.y * value_2.y;
}

Vector_Dec operator/(const Vector_Dec& value, double num) {
	return{ value.x / num, value.y / num };
}

double length(Vector_Dec x) {
	return std::sqrt(x.x * x.x + x.y * x.y);
}

std::ostream& operator<<(std::ostream& ostrm, Vector_Dec& value) {
	return ostrm << "(" << value.x << ", " << value.y << ")" << '\n';
}

std::istream& operator>>(std::istream& istrm, Vector_Dec& value) {
	return istrm >> value.x >> value.y;
}



Vector_Pol operator+(const Vector_Pol& value_1, const Vector_Pol& value_2) {
	double x1 = std::cos(value_1.phi) * value_1.r,
		x2 = std::cos(value_2.phi) * value_2.r,
		y1 = std::sin(value_1.phi) * value_1.r,
		y2 = std::sin(value_2.phi) * value_2.r;
	return{ std::sqrt((x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2)), std::atan((y1 + y2) / (x1 + x2)) };
}

Vector_Pol operator-(const Vector_Pol& value_1, const Vector_Pol& value_2) {
	double x1 = std::cos(value_1.phi) * value_1.r,
		x2 = std::cos(value_2.phi) * value_2.r,
		y1 = std::sin(value_1.phi) * value_1.r,
		y2 = std::sin(value_2.phi) * value_2.r;
	return{ std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)), std::atan((y1 - y2) / (x1 - x2)) };
}

Vector_Pol operator*(const Vector_Pol& value_1, double num) {
	return{ value_1.r * num, value_1.phi };
}

Vector_Pol operator/(const Vector_Pol& value_1, double num) {
	return{ value_1.r / num, value_1.phi };
}

std::ostream& operator<<(std::ostream& ostrm, Vector_Pol& value) {
	return ostrm << "(" << value.r << ", " << value.phi << ")" << '\n';
}

std::istream& operator>>(std::istream& istrm, Vector_Pol& value) {
	return istrm >> value.r >> value.phi;
}

Vector_Dec pltodc(Vector_Pol pl) {
	return { pl.r * cos(pl.phi), pl.r * sin(pl.phi) };
}

Vector_Pol dctopl(Vector_Dec dc) {
	return { length(dc), atan(dc.y / dc.x) };
}

