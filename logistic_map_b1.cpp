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
	int n;
	double x=0.09, r=0.88;
	ofstream fout("output.txt");
	
	
	fout<<0<<" "<<x<<endl;
	for(n=1;n<=200;n++)
	{
		x = x*exp(4*r*(1-x));
		fout<<n<<" "<<x<<endl;
	}
	
	
	
	return 0;
}
