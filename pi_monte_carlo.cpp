/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	int i,j,N=10,n_hits; 
	double x,y,pi_estimate,error;
	ofstream fout("output.txt");
	srand(time(0));


    for(i=1;i<=8;i++)
    {
    	n_hits=0;
    	for(j=1;j<=N;j++)
    	{
    		x=(double)rand()/(RAND_MAX);
    		y=(double)rand()/(RAND_MAX);
    		if(x*x+y*y < 1) n_hits++;
    		
    	}
    	pi_estimate=(double) 4*n_hits/N;
    	error=abs(M_PI-pi_estimate);
        fout<<N<<"   "<<pi_estimate<<"   "<<error<<endl;
        N*=10;
    }
    

	
    

	return 0;
} 
