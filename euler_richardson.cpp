/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
using namespace std;


double sign(double x)
{
	if(x<0) return -1;
	else return 1;
}

int main()
{
	int i;
	ofstream fout("output.txt");
	double g=9.81,R=6370000,k=0.0002,m=25;
	double y=6000,v=0,a,y_mid,v_mid,a_mid;
	double delta = 0.001;
	for(i=1; ;i++)
	{
	   a= -g*(1-2*y/R) - k*v*v/m*sign(v);
	   y_mid = y + 0.5*v*delta;
	   v_mid = v + 0.5*a*delta;
	   a_mid = -g*(1-2*y_mid/R) - k*v_mid*v_mid/m*sign(v_mid);
	   y = y + v_mid*delta;
	   v = v + a_mid*delta;
	   
	   fout<<i*delta<<"  "<<y<<"   "<<v<<endl;
	   if(y<=0) break;  
    }
	
	
	
	return 0;
}
