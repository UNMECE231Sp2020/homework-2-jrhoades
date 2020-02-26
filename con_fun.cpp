//con_fun.cpp
#include <iostream>
#include "declarations.h"
#include<cmath>

Complex::Complex() {
       	 _real = 0;
	 _imag = 0;
}
		
Complex::Complex(double real,double imag) {
	_real = real;
	_imag = imag;
}

Complex::Complex(const Complex &value) {
	_real = value._real;
	_imag = value._imag;
}	       
	       
	
double Complex::real() {
	return _real;
}

double Complex::imag() {
	return _imag;
}

void Complex::print() {
	std::cout<< "real: "<<_real << "imag: " <<_imag << std::endl;
}

Complex Complex::add(Complex a) {
	Complex value_add;
	value_add._real = _real + a._real;
	value_add._imag = _imag + a._imag;
	return value_add;
}
	
Complex Complex::sub(Complex b) {
	Complex value_sub;
	value_sub._real = _real - b._real;
	value_sub._imag = _imag - b._imag;
	return value_sub;
}
	
Complex Complex::mult(Complex c) {
	Complex value_mult;
	value_mult._real = (_real * c._real) - (_real * c._imag);
	value_mult._imag = (_imag * c._imag) + (_imag * c._real);
	return value_mult;
}
	
Complex Complex::div(Complex d) {
	Complex value_div;
	double denom = pow(d._real,2) + pow(d._imag,2);
	if (denom == 0) {
		std::cout << "You know what a chazzer is? It's a pig that cant divide by zero, and so can't you." << std::endl;
		value_div._real = 0;
		value_div._imag = 0;
		return value_div;
	}
	value_div._real = ((_real*d._real) + (_imag*d._imag)) / denom;
	value_div._imag = ((_imag*d._real) + (_real*d._imag)) / denom;
	return value_div;
}

Complex Complex::magnitude() {
	double magnitude;
	magnitude = sqrt(pow(_real,2) + pow(_imag,2));
	return magnitude;
}
	
Complex Complex::phase(Complex a) {
	double ph = atan(a._imag/a._real);
	ph = ph * (180/M_PI);
	return (ph<0) ? -ph : ph;
}		

Complex Complex::operator+ (Complex v) {
	Complex temp = add(v);
	//temp._real = _real + value._real;
	//temp._imag = _imag + value._imag;
		
	return temp;
}
			
Complex Complex::operator- (Complex v) {
	Complex temp = sub(v);
	//temp._real = _real - value._real;
	//temp._imag = _imag - value._imag;
			
	return temp;
}


Complex Complex::operator* (Complex v) {
	Complex temp = mult(v);
	//temp._real = _real * value._real;
	//temp._imag = _imag * value._imag;
			
	return temp;
}


Complex Complex::operator/ (Complex v) {
	Complex temp = div(v);
	//temp._real = _real / value._real;
	//temp._imag = _imag / value._imag;
			
	return temp;
}
	
Complex Complex::operator= (Complex v) {
	_real = v._real;
	_imag = v._imag;	
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Complex v) {
	out << v.real << " " << v.imag;
	return out;
}

std::istream& operator>>(std::istream &in, const Complex v) {
	in >> v.real >> v.imag;
	return in;
}
