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
	int i,n=950;
	double a=-1,b=1,dx,S=0,x_i,integral;	          	                                                                             
	ofstream fout("output.txt");
	
	dx=(double)(b-a)/n;
/*    
    for(i=0;i<=n;i++)
     {
     	x_i=a+i*dx;
     	if(i==0 || i==n) S+=f(x_i);
     	else if(i%2==0) S+=2*f(x_i);
     	else if(i%2==1) S+=4*f(x_i);
     }
     
    integral=S*dx/3;
    
    cout<<integral<<endl;
 */   
    
    
    for(i=0;i<=n;i++)
     {
     	x_i=a+i*dx;
     	if(i==0 || i==n) S+=f2(x_i);
     	else if(i%2==0) S+=2*f2(x_i);
     	else if(i%2==1) S+=4*f2(x_i);
     }
     
    integral=S*dx/3;
    
    cout<<integral<<endl;
   
	    
	return 0;
}
