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
	return exp(-x*x/2);
}

int main()
{
	int i,n=100000,j,j_min;
	double delta=0.5,delta_i,x_i,x_trial,w,r,I=0,H[100001],nr_accepted=0,ok=0,x[100002],x_average=0,x_squared_average=0,x_ij_average=0,min=100000;       	                                                                             
	ofstream fout("output.txt");
	srand(time(0));
	
	for(i=0;i<=100000;i++) H[i]=0;
	x_i=delta*( (double) rand() / (RAND_MAX) );  //random number between 0 and delta
    x[0]=x_i;

    for(i=1;i<=n;i++)
	{
		delta_i=delta*( 2*( (double) rand() / (RAND_MAX)) - 1 );  //random number between -delta and delta
		x_trial=x_i+delta_i;
		w=p(x_trial)/p(x_i);
		if(w>=1)
		{
			x_i=x_trial;
			nr_accepted++;
		} 
		else if(w<1)
		{
			r=(double) rand() / (RAND_MAX) ;  //random number between 0 and 1
			if(r<=w)
			{
				x_i=x_trial;
				nr_accepted++;
			}
		}
		H[50000+(int)(x_i/0.2)]++;
		I+=x_i*x_i;
		x[i]=x_i;
		if(I/i >= 0.95 && I/i <= 1.05) 
		{
			if(ok==10) cout <<"Equilibration time: "<<i-10<<" steps"<<endl;
			ok++;
		}
	}
    H[50000]/=2;
    
    cout<<"Average x^2: "<<I/n<<endl;
    cout<<"Acceptance ratio: "<<nr_accepted/n<<endl;
    for(i=49950;i<=50050;i++) fout<<(i-50000)*0.2<<"  "<<H[i]/H[50000]<<endl;
     
    
    for(j=0;j<=1000;j+=1)
    {  
    	x_average=0;
    	x_squared_average=0;
    	x_ij_average=0;
    
        for(i=0;i<=n;i++) 
    	{
	    	x_average+=x[i]/n;
	    	x_squared_average+=x[i]*x[i]/n;
	    	if( (i+j)<=n ) x_ij_average+=x[i+j]*x[i]/n;
	    	else x_ij_average+=x[(i+j)-(n+1)]*x[i]/n;
    	}
	
        if(abs( (x_ij_average-x_average*x_average)/(x_squared_average-x_average*x_average) ) < min)
    	{
		    min=abs( (x_ij_average-x_average*x_average)/(x_squared_average-x_average*x_average) );
			j_min=j;	
    	} 
    }

    cout<<"C(j)_min: "<<min<<" "<<" for j = "<<j_min<<endl; 

	return 0;
}
