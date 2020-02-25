//declarations.h
#include <iostream>
//Class declarations
class Complex {
	private:
		struct complex_ {
			double real;
			double imag;
		};
		typedef struct complex_ Complex1;
	
	public:
		Complex();
		Complex(double real, double imag);
		Complex(const Complex &Complex);
		~Complex();

		double real() const;
		double imag() const;
		size_t size() const;
		void print();

		void add(double c1, double c2);
		void sub(double value);
		void mult(double value);
		void div(double value);
		
		void conj(double value);
		void mag(double value);
		void phase(double value);

		bool empty();
};



/*
void hdler_a(Complex(*complex_fn)(Complex, Complex), Complex c1, Complex c2);


void hdler_b(double (*complex_fn)(Complex),Complex c1);
*/


                                                          
