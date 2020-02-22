//con_fun.cpp

void print_complex(Complex c){
	if(c.imag < 0){
		printf("%.3lf - %.3lf\n", c.real, -c.imag);
	}
	else{
		printf("%.3lf + %.3lf\n", c.real, c.imag);
	      }
}

Complex complex_add(Complex c1, Complex c2) {
	Complex c = {c1.real+c2.real, c1.imag+c2.imag};
	return c;
}


Complex complex_sub(Complex c1, Complex c2) {
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
		printf("You know what a chazzer is? It's a pig that can't divide by a 0. And so can't you!\n");
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


void hdler_a(Complex (*complex_fn)(Complex, Complex), Complex c1, Complex c2){
	printf("%lf %lf\n", complex_fn(c1,c2).real, complex_fn(c1,c2).imag);
}

void hdler_b(double (*complex_fn)(Complex), Complex c1){
	printf("%lf \n", complex_fn(c1));
}
