//con_fun.cpp
#include <iostream>
#include "declarations.h"

 class Complex {
	private:		
		double _real;
		double _imag;
	public:
		Complex() : _real(0), _imag(0){
		}
		
		Complex(double real,double imag);{
			_real = real;
			_imag = imag;
		}

		Complex(const Complex &value){
		       _real = value._real;
	       	       _imag = value._imag;
		}	       
	       
		~Complex(){
			;
		}
		
		void set(double real, double imag){
			_real = real;
			_imag = imag;
		}
		double real() {
			return _real;
		}
		double imag() {
			return _imag;
		}

		void print() {
			std::cout<< "real: "<< _real << "imag: " << _imag << std::endl;
		}
		
		Complex operator+(Complex value) {
			Complex temp = add(value);
			//temp._real = _real + value._real;
			//temp._imag = _imag + value._imag;
			
			return temp;
		}
			
		Complex operator-(Complex value) {
			Complex temp = sub(value);
			//temp._real = _real - value._real;
			//temp._imag = _imag - value._imag;
			
			return temp;
		}


		Complex operator*(Complex value) {
			Complex temp = mult(value);
			//temp._real = _real * value._real;
			//temp._imag = _imag * value._imag;
			
			return temp;
		}


		Complex operator/(Complex value) {
			Complex temp = div(value);
			//temp._real = _real / value._real;
			//temp._imag = _imag / value._imag;
			
			return temp;
		}
	
		Complex operator=(Complex value) {
			Complex temp;
			temp._real = _real;
			temp._imag = _imag;
			
			return *this;
		}
		
		bool operator !=(Complex value) {
			return ( (_real != value._real) && \
				 (_imag != value._imag) );
		}

		
		bool operator ==(Complex value) {
			return ( (_real == value._real) && (_imag == value._imag) );
		}

		friend std::ostream& operator<<(std::ostream &out, const Complex &v) {
			out << v._real << " " << v._imag;

			return out;
		}
		friend std::istream& operator>>(std::istream &in, const Complex &v) {
			in >> v._real >> v._imag;

			return in;
		}

		bool empty();
};


void Complex::print_complex(Complex c){
	if(c.imag < 0){
		printf("%.3lf - %.3lf\n", c.real, -c.imag);
	}
	else{
		printf("%.3lf + %.3lf\n", c.real, c.imag);
	      }
}

Complex add(Complex c1, Complex c2) {
	Complex c = {c1.real+c2.real, c1.imag+c2.imag};
	return c;
}


Complex sub(Complex c1, Complex c2) {
	Complex c = {c1.real-c2.real, c1.imag-c2.imag};
	return c;
}

Complex complex_mult(Complex c1, Complex c2) {
	Complex c = {(c1.real*c2.real)+(c1.imag*c2.imag*-1),(c1.imag*c2.real)+(c1.real*c2.imag)};
	return c;
}

Complex complex_div(Complex c1, Complex c2){
	double denom = magnitude(c2)*magnitude(c2);
	Complex c = complex_mult(c1, complex_conj(c2));
	c.real /= denom;
	c.imag /= denom;
	
	if(denom==0){						
		std::cout<<"You know what a chazzer is? It's a pig that can't divide by a 0. And so can't you!"<<c std::endl;
	}
	else{		
		return c;
	 }
}

Complex complex_conj(Complex c){
	c.imag *= -1;
	return c;
}


double magnitude(Complex c){
	return sqrt((c.real*c.real) + (c.imag*c.imag));
}

double phase(Complex c){
	double ph = atan(c.imag/c.real);
	ph = ph * (180/M_PI);
	return (ph<0) ? -ph : ph;
}

/*
void hdler_a(Complex (*complex_fn)(Complex, Complex), Complex c1, Complex c2){
	printf("%lf %lf\n", complex_fn(c1,c2).real, complex_fn(c1,c2).imag);
}

void hdler_b(double (*complex_fn)(Complex), Complex c1){
	printf("%lf \n", complex_fn(c1));
}*/ 

