//declarations.h
#include <iostream>
//Class declarations
class Complex {
	private:
		double _real;
		double _imag;
	public:

		Complex();
		Complex(double real, double imag);
		Complex(const Complex &value);

		double real();
		double imag();
		void print();

		Complex add(Complex a);
		Complex sub(Complex b);
		Complex mult(Complex c);
		Complex div(Complex d);
	
		double magnitude();
		double phase();

		Complex operator+ (Complex v);
		Complex operator- (Complex v);
		Complex operator* (Complex v);
		Complex operator/ (Complex v);
		Complex operator= (Complex v);

		friend std::ostream& operator<<(std::ostream &out, const Complex v);
		friend std::istream& operator>>(std::istream &in, Complex &v);
};                     
