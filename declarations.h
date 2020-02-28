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
		Complex(double real);
		void Display();
		Complex(const Complex &Value);

		double real();
		double imag();
		void print();

		Complex add(Complex a);
		Complex sub(Complex b);
		Complex mult(Complex c);
		Complex div(Complex d);

		Complex conjugate();	
		double magnitude();
		double phase();

		Complex operator+ (Complex v);
		Complex operator- (Complex v);
		Complex operator* (Complex v);
		Complex operator/ (Complex v);
		Complex operator= (Complex v);

		friend std::ostream& operator<<(std::ostream &out, const Complex Value);
		friend std::istream& operator>>(std::istream &in, Complex &Value);
};                     
