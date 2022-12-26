#pragma once
#include <iostream>
#include <cmath>

struct Vector_Dec
{
	double x = 0, y = 0;
};
Vector_Dec operator +(const Vector_Dec& value, const Vector_Dec& value_2);

Vector_Dec operator -(const Vector_Dec& value_2, const Vector_Dec& value);

Vector_Dec operator *(const Vector_Dec& value, double num);

Vector_Dec operator *(double num, const Vector_Dec& value);


double operator*(const Vector_Dec& value_1, const Vector_Dec& value_2);

Vector_Dec operator/(const Vector_Dec& value, double num);

double length(Vector_Dec x);

std::ostream& operator<<(std::ostream& ostrm, Vector_Dec& value);

std::istream& operator>>(std::istream& istrm, Vector_Dec& value);


struct Vector_Pol {
	double r = 0, phi = 0;
};

Vector_Pol operator+(const Vector_Pol& value_1, const Vector_Pol& value_2);

Vector_Pol operator-(const Vector_Pol& value_1, const Vector_Pol& value_2);

Vector_Pol operator*(const Vector_Pol& value_1, double num);

Vector_Pol operator/(const Vector_Pol& value_1, double num);

std::ostream& operator<<(std::ostream& ostrm, Vector_Pol& value); 

std::istream& operator>>(std::istream& istrm, Vector_Pol& value);

Vector_Dec pltodc(Vector_Pol pl);

Vector_Pol dctopl(Vector_Dec dc);
