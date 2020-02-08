/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int I=22,a=205,c=29573,m=139968;
    
double generate()
{
    I=(a*I+c)%m;
    return I;
}

int main()
{
	int i;
	double v[201]; 
	ofstream fout("output.txt");
	srand(time(0));
    
    for(i=1;i<=200;i++)
    {
    	v[i]=generate()/m;
    }

/*
    for(i=1;i<=200;i++)
    {
    	v[i]=(double)rand()/(RAND_MAX);
    }
*/

     for(i=1;i<=100;i++)
     {
     	fout<<v[i]<<"  "<<v[i+100]<<endl;  //output for plotting with matlab
     }
	
    

	return 0;
} 
