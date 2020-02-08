/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
using namespace std;



int main()
{
	int n;
	double x_a=0.6, x_b=0.6+0.00001, r=0.92;
	ofstream fout("output.txt");
	
	
	fout<<0<<" "<<x_a<<" "<<x_b<<endl;
	for(n=1;n<=200;n++)
	{
		x_a = 4*r*x_a*(1-x_a);
		x_b = 4*r*x_b*(1-x_b);
		fout<<n<<" "<<x_a<<" "<<x_b<<" "<<endl;  //dx_n = x_a - x_b
	}
	
	
	
	return 0;
}
