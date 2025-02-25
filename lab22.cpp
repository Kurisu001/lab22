#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
    public:
        double real;
        double imag;
        ComplexNumber(double,double);
        ComplexNumber operator+(const ComplexNumber &);
        ComplexNumber operator-(const ComplexNumber &);
        ComplexNumber operator*(const ComplexNumber &);
        ComplexNumber operator/(const ComplexNumber &);
        friend ComplexNumber operator+(double ,const ComplexNumber &);
        friend ComplexNumber operator-(double ,const ComplexNumber &);
        friend ComplexNumber operator*(double ,const ComplexNumber &);
        friend ComplexNumber operator/(double ,const ComplexNumber &);
        bool operator==(const ComplexNumber &);
        friend bool operator==(double ,const ComplexNumber &);
        double abs();
        double angle();
    };
    


ComplexNumber::ComplexNumber(double x = 0,double y = 0){
    real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
    return ComplexNumber(real+c.real,imag+c.imag);
}
ComplexNumber operator+(double a,const ComplexNumber &c){
    return ComplexNumber(a+c.real,0+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
    return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber operator-(double a ,const ComplexNumber &c){
    return ComplexNumber(a-c.real,0-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    return ComplexNumber(((real*c.real)-(imag*c.imag)),((imag*c.real)+(real*c.imag)));
}
ComplexNumber operator*(double a,const ComplexNumber &c){
    return ComplexNumber(((a*c.real)-(0*c.imag)),((0*c.real)+(a*c.imag)));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denominator = pow(c.real,2)+pow(c.imag,2);
    if (denominator == 0) throw runtime_error("Division by zero");
    return ComplexNumber((((real*c.real)+(imag*c.imag))/denominator),((imag*c.real)-(real*c.imag))/denominator);
}
ComplexNumber operator/(double a ,const ComplexNumber &c){
    double denominator = pow(c.real,2)+pow(c.imag,2);
    if (denominator == 0) throw runtime_error("Division by zero");
    return ComplexNumber((((a*c.real)+(0*c.imag))/denominator),((0*c.real)-(a*c.imag))/denominator);
}

bool ComplexNumber::operator == (const ComplexNumber &c){
    return real==c.real && imag==c.imag;
}

bool operator == (double a,const ComplexNumber &c){
    return a==c.real && 0==c.imag;
}

ostream & operator <<(ostream &os, const ComplexNumber &c){
	if(c.imag == 0) os << c.real;
	else if(c.real == 0) os << c.imag << "i";
	else if(c.imag < 0) os << c.real << c.imag << "i";
	else os << c.real << "+" << c.imag << "i";
	return os;
}

double ComplexNumber::abs(){
    return sqrt(pow(real,2)+pow(imag,2));
}
double ComplexNumber::angle() {
	double angleInRadians = atan2(imag, real);
	double angleInDegrees = angleInRadians * (180 / M_PI);
	return angleInDegrees;
}

int main(){
    ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);
    cout << 2+a << "\n";
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << a+2.5 << "\n";
    cout << 2.5+a << "\n";
    cout << a-1.5 << "\n";
    cout << 1.5-a << "\n";
    cout << b+ComplexNumber(0,2.5) << "\n";
    cout << c-c << "\n";
    cout << "-----------------------------------\n";
    
    ComplexNumber d = (a+b)/c;
    ComplexNumber e = b/(a-c);
    cout << d << "\n";
    cout << e << "\n";
    cout << c*2 << "\n";
    cout << 0.5*c << "\n";
    cout << 1/c << "\n";
    cout << "-----------------------------------\n";
    
    cout << ComplexNumber(1,1).abs() << "\n";
    cout << ComplexNumber(-1,1).abs() << "\n";
    cout << ComplexNumber(1.5,2.4).abs() << "\n";
    cout << ComplexNumber(3,4).abs() << "\n";
    cout << ComplexNumber(69,-9).abs() << "\n";		
    cout << "-----------------------------------\n";	
    
    cout << ComplexNumber(1,1).angle() << "\n";
    cout << ComplexNumber(-1,1).angle() << "\n";
    cout << ComplexNumber(-1,-1).angle() << "\n";
    cout << ComplexNumber(1,-1).angle() << "\n";
    cout << ComplexNumber(5,2).angle() << "\n";
    cout << "-----------------------------------\n";
    
    cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
    cout << (ComplexNumber(1,1) == 1) << "\n";
    cout << (0 == ComplexNumber()) << "\n";
}