
/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/


#include<iostream.h>
#include<conio.h>
class complex
{
double real,imaginary;
public:
complex(){}    // DEFAULT CONSTRUCTOR
complex(double r,double i)    // PARAMETERIZED CONSTRUCTOR
{
real=r;
imaginary=i;
}
void complex::display()
{
if(imaginary>0)
{
cout<<real<<"+"<<imaginary<<"i";
}
else
{
cout<<real<<" "<<imaginary<<"i";
}
}
complex operator + (complex&other)
{
complex c3;
c3.real=real+other.real;
c3.imaginary=imaginary+other.imaginary;
return c3;
}
complex operator - (complex&other)
{
complex c4;
c4.real=real-other.real;
c4.imaginary=imaginary-other.imaginary;
return c4;
}
complex operator * (complex&other)
{
complex c5;
c5.real=real*other.real;
c5.imaginary=imaginary*other.imaginary;
return c5;
}
complex operator / (complex&other)
{
complex c6;
c6.real=real/other.real;
c6.imaginary=imaginary/other.imaginary;
return c6;
}
friend ostream&operator<<(ostream&take,complex&comp)
{
take<<comp.real;
take<<comp.imaginary;
return take;
}
friend istream&operator>>(istream&i,complex&comp)
{
cout<<"Enter the real part:";
i>>comp.real;
cout<<"Enter the imaginary part:";
i>>comp.imaginary;
return i;
}
};
int main()
{
clrscr();
complex c1,sum,sub,mul,div;
cin>>c1;
complex c2(3,5);
cout<<"\n First complex number is:";
c1.display();
cout<<"\n Second complex number is:";
c2.display();
cout<<"\n";
sum=c1+c2;
cout<<"\n Addition of two complex number is:";
sum.display();
sub=c1-c2;
cout<<"\n Subtraction of two complex number is:";
sub.display();
mul=c1*c2;
cout<<"\n Multiplication of two complex number is:";
mul.display();
div=c1/c2;
cout<<"\n Division of two complex number is:";
div.display();
getch();
}
