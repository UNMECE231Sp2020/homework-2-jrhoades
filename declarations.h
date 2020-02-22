//declarations.h
#include <iostream>
//Class declarations
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
	       
		~Complex();
		
		void (*set_f)(struct Complex *, double, double);
		double (*getreal_f) (struct Complex);
		double (*getimag_f) (struct Complex);
		void (*print_f) (struct Complext);

		void print_complex(Complex c);

		Complex complex_add(Complex c1, Complex c2);
		Complex complex_sub(Complex c1, Complex c2);
		Complex complex_mult(Complex c1, Complex c2);
		Complex complex_div(Complex c1, Complex c2);
		Complex complex_conj(Complex c);

		double magnitude(Complex c);
		double phase(Complex c);

		bool empty();
 };
/*
struct _complex {
	double real;
	double imag;
};
typedef struct _complex Complex;
*//*
void hdler_a(Complex(*complex_fn)(Complex, Complex), Complex c1, Complex c2);


void hdler_b(double (*complex_fn)(Complex),Complex c1);
*/


~                                                          
