#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>
#include <string>

class Complex {
	private:
	// atributes of complex numbers
		float real;
		float imag;
		float mag;
		float arg;
		std::string rec = " + ";
		std::string pol = "e^i";
	public:
		Complex (){real = 0; imag = 0; mag = 0; arg = 0;}
		Complex (float re, float im);
		Complex (Complex & in);
		
		void set_rectangular(float re, float im);
		void set_polar(float r, float theta);
		
		void print_rect();
		void print_pol();
		
		void operator=(const Complex & comp_in);
		
		Complex operator+(Complex & right);
		Complex operator+(float rhs);
		void operator+=(Complex & rhs);
		void operator+=(float rhs);
		
		Complex operator-(Complex & right);
		Complex operator-(float rhs);
		void operator-=(Complex & rhs);
		void operator-=(float rhs);
		
		Complex operator*(Complex & rhs);
		Complex operator*(float rhs);
		void operator*=(Complex & rhs);
		void operator*=(float rhs);
		
		Complex operator/(Complex & rhs);
		Complex operator/(float rhs);
		void operator/=(Complex & rhs);
		void operator/=(float rhs);
		
		void set_pol();
		void set_rect();
};

#endif
