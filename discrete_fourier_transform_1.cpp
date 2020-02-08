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
	int i,j,n=1024,k;
	double f_real[1025],f_imag[1025],g_real[1025],g_imag[1025],x,elapsed_secs,execution_time=0;
	clock_t begin,end;
	ofstream fout("output.txt");

//for(k=1;k<=100;k++)
//{
	
	for(i=-512;i<512;i++)
	{
		f_real[i+512]=f_gauss(i*0.01);  //initial data
		f_imag[i+512]=0;
	}
		
	for(i=0;i<1024;i++)
	{
		g_real[i]=0;
		g_imag[i]=0;
	}
	
	begin = clock();
	for(i=-512;i<512;i++)   //discrete fourier transform
	{
	   for(j=-512;j<512;j++)        
	   {
	   	 x=2*M_PI*i*j/n;
	   	 g_real[i+512] += f_real[j+512]*cos(x*M_PI/180) + f_imag[j+512]*sin(x*M_PI/180);  //g[i]=sum_j(f[j]*exp(-i*2*pi*i*j/n))
		 g_imag[i+512] += -f_real[j+512]*sin(x*M_PI/180) + f_imag[j+512]*cos(x*M_PI/180);
	   }
	   g_real[i+512]/=sqrt(n);
	   g_imag[i+512]/=sqrt(n);
	}
	end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    execution_time+=elapsed_secs;
    
//}

//for(i=-512;i<512;i++) fout<<i*0.01<<"  "<<f_real[i+512]<<endl;	
for(i=-512;i<512;i++) fout<<i*2*M_PI/(0.01*(n-1))<<"  "<<sqrt(g_real[i+512]*g_real[i+512]+g_imag[i+512]*g_imag[i+512])<<endl; 
//cout<<execution_time;

	return 0;
}
