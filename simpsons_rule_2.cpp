/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return sqrt(1/(2*M_PI))*exp(-x*x);
}

double f2(double x)
{
	return 4*sqrt(1-x*x); 
}

int main()
{
	int i,n=10000;
	double a=-1,b=1,dx,S=0,x_i,S_n,T_2n,T_n;	          	                                                                             
	ofstream fout("output.txt");
	
	dx=(double)(b-a)/n;
    
    for(i=0;i<=n;i++) //trapezoidal approximation for n intervals
     {
     	x_i=a+i*dx;
     	if(i==0 || i==n) S+=f(x_i)/2;
     	else S+=f(x_i);
     }
     T_n=S*dx;
     
     S=0;
     n=2*n;
     dx=(double)(b-a)/n; //trapezoidal approximation for 2n intervals
     
     for(i=0;i<=n;i++)
     {
     	x_i=a+i*dx;
     	if(i==0 || i==n) S+=f(x_i)/2;
     	else S+=f(x_i);
     }
     T_2n=S*dx;
    
     S_n=(4*T_2n - T_n)/3;
     
     cout<<S_n<<endl;
	    
	return 0;
}
