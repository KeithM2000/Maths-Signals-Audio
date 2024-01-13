#include "Complex.h"

Complex::Complex (float re, float im){
	real = re;
	imag = im;
	this->set_pol();
}

Complex::Complex (Complex & in){
	real = in.real;
	imag = in.imag;
	mag = in.mag;
	arg = in.arg;
}

void Complex::set_pol(){
	mag = real*real + imag*imag;
	mag = sqrt(mag);
	arg = atan2(imag, real);
}

void Complex::set_rect(){
	real = mag*cos(arg);
	imag = mag*sin(arg);
}

void Complex::operator=(const Complex & comp_in){
	real = comp_in.real;
	imag = comp_in.imag;
	mag = comp_in.mag;
	arg = comp_in.arg;
}

Complex Complex::operator+(Complex & right){
	Complex Res = Complex((real+right.real), (imag+right.imag));
	return Res;
}

Complex Complex::operator+(float rhs){
	Complex Res = Complex((real+rhs), imag);
	return Res;	
}
void Complex::operator+=(Complex & rhs){
	real+=rhs.real;
	imag+=rhs.imag;
	this->set_pol();
}

void Complex::operator+=(float rhs){
	real+=rhs;
	this->set_pol();
}

Complex Complex::operator-(Complex & right){
	Complex Res = Complex((real-right.real), (imag-right.imag));
	return Res;	
}

Complex Complex::operator-(float rhs){
	Complex Res = Complex((real-rhs), imag);
	return Res;		
}

void Complex::operator-=(Complex & rhs){
	real -= rhs.real;
	imag -= rhs.imag;
	this->set_pol();
}

void Complex::operator-=(float rhs){
	real -= rhs;
	this->set_pol();
}

Complex Complex::operator*(Complex & rhs){
	Complex res;
	res.mag = mag*rhs.mag;
	res.arg = arg+rhs.arg;
	res.set_rect();
	return res;
}

Complex Complex::operator*(float rhs){
	Complex res = Complex((real*rhs), (imag*rhs));
	return res;
}

void Complex::operator*=(Complex & rhs){
	mag *= rhs.mag;
	arg += rhs.arg;
	this->set_rect();
}

void Complex::operator*=(float rhs){
	real*=rhs;
	imag*=rhs;
	this->set_pol();
}

Complex Complex::operator/(Complex & rhs){
	Complex res;
	res.mag = mag/rhs.mag;
	res.arg = arg-rhs.arg;
	res.set_rect();
	return res;	
}

Complex Complex::operator/(float rhs){
	Complex res = Complex((real/rhs), (imag/rhs));
	return res;	
}

void Complex::operator/=(Complex & rhs){
	mag /= rhs.mag;
	arg -= rhs.arg;
	this->set_rect();	
}

void Complex::operator/=(float rhs){
	real/=rhs;
	imag/=rhs;
	this->set_pol();	
}

void Complex::print_rect(){
	std::cout<< real << rec << imag << 'i' << std::endl;
}
void Complex::print_pol(){
	std::cout<< mag << pol << arg << std::endl;
}
