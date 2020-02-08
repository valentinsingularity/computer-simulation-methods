/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <cmath>
using namespace std;



int main()
{
	int i,n=10000; // n -> infinity
	double x=0.5,r,lambda;  // x - the value does not matter
	ofstream fout("output.txt");
	
	for(r=0.01;r<=1;r+=0.01)
	{
		lambda=0;
		for(i=0;i<n;i++)  //computes the Lyapunov exponent for the first map
		{
			lambda+=log(abs(4*r*(1-2*x)))/n;
			x = 4*r*x*(1-x);
		}
		fout<<r<<" "<<lambda<<" ";
		
		lambda=0;
		for(i=0;i<n;i++)  //computes the Lyapunov exponent for the second map
		{
			lambda+=log(abs(exp(4*r*(1-x))*(1-4*r*x)))/n;
			x=x*exp(4*r*(1-x));
		}
		fout<<lambda<<" ";
		
		lambda=0;
		for(i=0;i<n;i++)  //computes the Lyapunov exponent for the third map
		{
			lambda+=log(abs(r*M_PI*cos(M_PI*x)))/n;
			x=r*sin(M_PI*x);
		}
		fout<<lambda<<endl;
		
		
	}
	
	
	return 0;
}
