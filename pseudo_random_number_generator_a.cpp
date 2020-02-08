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

int I=22, a=8121,c=28411,m=134456;
    
double generate()
{
    I=(a*I+c)%m;
    return I;
}

int main()
{
	int j,v[140000];
	ofstream fout("output.txt");
	//I=time(0)
    
    cout<<generate()/m<<endl;  //generates the next random number
    
    for(j=1;;j++)  //checks the period
    {
    	I=(a*I+c)%m;
    	if(v[I]==1)
		{
			cout<<"Period = "<<j-1<<endl;
			break;
		} 
    	else v[I]=1;
    	fout<<I/m<<endl;
    }
    

	return 0;
} 
