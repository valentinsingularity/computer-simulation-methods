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

double f_gauss(double x)
{
	return exp(-x*x/2);
}

int main()
{
	int i,j,n=1000;
	double tau,f_real[1001],f_imag[1001],g_real[1001],g_imag[1001],f_back_real[1001],f_back_imag[1001],x;
	tau=M_PI/(n-1);
	ofstream fout("output.txt");
	
	
	for(i=0;i<1000;i++)
	{
		f_real[i]=sin(i*tau);  //initial data
		f_imag[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		g_real[i]=0;
		g_imag[i]=0;
		f_back_real[i]=0;
		f_back_imag[i]=0;
	}

	for(i=-500;i<500;i++)   //discrete fourier transform (forward transformation)
	{
	   for(j=0;j<1000;j++)        
	   {
	   	 x=2*M_PI*i*j/n;
	   	 g_real[i+500] += f_real[j]*cos(x*M_PI/180) - f_imag[j]*sin(x*M_PI/180);  //g[i]=sum_j(f[j]*exp(-i*2*pi*i*j/N))
		 g_imag[i+500] += -f_real[j]*sin(x*M_PI/180) + f_imag[j]*cos(x*M_PI/180);
	   }
	   g_real[i+500]/=sqrt(n);
	   g_imag[i+500]/=sqrt(n);
	}
	
	for(i=0;i<1000;i++)   //discrete fourier transform (backward transformation)
	{
	   for(j=-500;j<500;j++)        
	   {
	   	 x=2*M_PI*i*j/n;
	   	 f_back_real[i] += g_real[j+500]*cos(x*M_PI/180) - g_imag[j+500]*sin(x*M_PI/180);  //f_back[i]=sum_j(g[j]*exp(i*2*pi*i*j/N))
		 f_back_imag[i] += g_real[j+500]*sin(x*M_PI/180) + g_imag[j+500]*cos(x*M_PI/180);
	   }
	   f_back_real[i]/=sqrt(n);
	   f_back_imag[i]/=sqrt(n);
	}
	


//for(i=0;i<1000;i++) fout<<i*tau<<"  "<<f_real[i]<<endl;	
//for(i=-500;i<500;i++) fout<<i<<"  "<<sqrt(g_real[i+500]*g_real[i+500]+g_imag[i+500]*g_imag[i+500])<<endl;
for(i=0;i<1000;i++) fout<<i*tau<<"  "<<sqrt(f_back_real[i]*f_back_real[i]+f_back_imag[i]*f_back_imag[i])/57.23<<endl;  //plotting with matlab

	return 0;
}
