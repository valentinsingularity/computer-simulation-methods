/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double p(double x)
{
	if(x>=0) return exp(-x);
	else return 0;
}

int main()
{
	int i,n=1000;
	double delta=1,delta_i,x_i,x_trial,w,r,I=0,H[5001];       	                                                                             
	ofstream fout("output.txt");
	srand(time(0));
	
	for(i=0;i<=5000;i++) H[i]=0;
	x_i=delta*( (double) rand() / (RAND_MAX) );  //random number between 0 and delta
	
	for(i=1;i<=500;i++) //letting the system to equilibrate for 500 steps 
	{
		delta_i=delta*( 2*( (double) rand() / (RAND_MAX)) - 1 );  //random number between -delta and delta
		x_trial=x_i+delta_i;
		w=p(x_trial)/p(x_i);
		if(w>=1) x_i=x_trial;
		else if(w<1)
		{
			r=(double) rand() / (RAND_MAX) ;  //random number between 0 and 1
			if(r<=w) x_i=x_trial;
			
		}
	}

    for(i=1;i<=n;i++) //compute averages
	{
		delta_i=delta*( 2*( (double) rand() / (RAND_MAX)) - 1 );  //random number between -delta and delta
		x_trial=x_i+delta_i;
		w=p(x_trial)/p(x_i);
		if(w>=1)
		{
			I+=x_trial*x_trial;
			x_i=x_trial;
		} 
		else if(w<1)
		{
			r=(double) rand() / (RAND_MAX) ;  //random number between 0 and 1
			if(r<=w)
			{
				I+=x_trial*x_trial;
				x_i=x_trial;
			}
		}
		H[(int)(x_i/0.2)]++;
	}
    
    cout<<"Average x^2: "<<I/n<<endl;
    for(i=0;i<=30;i++) fout<<i*0.2<<"  "<<H[i]<<endl;
 
	return 0;
}
