/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler euler.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice it is the same language as in professor Kinga Lipskoch's course Programming in C++. 
*/

#include <fstream>
using namespace std;


double sign(double x)   //function to compute the sign of a number
{
	if(x<0) return -1;
	else return 1;
}

int main()
{
	int i;
	ofstream fout("output.txt");     //output file
	double g=9.81,R=6370000,k=0.0002,m=25,a;     //numerical constants
	double delta = 0.001;         //time step dt
	double y=6000;             // y-position, v- velocity, no need to store the results in data structures
	double v=0;
	for(i=1; ;i++)
	{
	   a= -g*(1-2*y/R) - k*v*v/m*sign(v);    //computes the acceleration a[n] at this step
	   y = y + v*delta;                     //determines the new values of the position and velocity: y[n+1]=y[n]+v[n]*dt
	   v = v + a*delta;                     //v[n+1]=v[n]+a[n]*dt;
	   
       fout<<i*delta<<"  "<<y<<"   "<<v<<endl;       //prints the data in the file for plotting with matlab
       if(y<0) break;         //stopping condition of the loop
    }
	
	return 0;
}
