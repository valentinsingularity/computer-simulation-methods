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
#include <vector>
using namespace std;

double f_gauss(double x)
{
	return exp(-x*x/2);
}

vector< vector<double> > fft(int n, vector< vector<double> > f) 
{
	if(n==1) return f;
	else
	{
		double x;
		vector< vector<double> > a(2, vector<double>(n/2));
		vector< vector<double> > b(2, vector<double>(n/2));
		for(int i=0;i < n; i++)
		{
			if(i%2 == 0)
			{
				a[0][i/2]=f[0][i]; //real part
				a[1][i/2]=f[1][i]; //imaginary part
			}
			else
			{
				b[0][(i-1)/2]=f[0][i]; //real part
				b[1][(i-1)/2]=f[1][i]; //imaginary part
			}
		}
		
		vector< vector<double> > g = fft(n/2,a);
		vector< vector<double> > u = fft(n/2,b);
		
		vector< vector<double> > c(2, vector<double>(n));
		for(int k=0;k<=(n/2 -1);k++)
		{
			x=2*M_PI*k/n;
			c[0][k] = g[0][k] + u[0][k]*cos(x*M_PI/180) + u[1][k]*sin(x*M_PI/180);      //c[o][k]=c_real[k] ; c[1][k]=c_imag[k]
			c[1][k] = g[1][k] - u[0][k]*sin(x*M_PI/180) + u[1][k]*cos(x*M_PI/180);
			c[0][k + n/2] = g[0][k] - u[0][k]*cos(x*M_PI/180) - u[1][k]*sin(x*M_PI/180); 
			c[1][k + n/2] = g[1][k] + u[0][k]*sin(x*M_PI/180) - u[1][k]*cos(x*M_PI/180);
		}
		
		return c;
		
	}
}


int main()
{
	int i,k,n=1024;
	double elapsed_secs,execution_time=0;
	vector< vector<double> > f(2, vector<double>(n));
	vector< vector<double> > g(2, vector<double>(n));
	clock_t begin,end;
	ofstream fout("output.txt");

//for(k=1;k<=100;k++)
//{    
	for(i=-512;i<512;i++)
	{
		f[0][i+512]=f_gauss(i*0.01);  //initial data
		f[1][i+512]=0;
	}
	
	begin = clock();
	
	g=fft(n,f);
	
	end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    execution_time+=elapsed_secs;
//}	
	
	for(i=-512;i<512;i++) fout<<i*2*M_PI/(0.01*(n-1))<<"  "<<sqrt(g[0][i+512]*g[0][i+512]+g[1][i+512]*g[1][i+512])<<endl;
	
//cout<<execution_time;

    return 0;	
}
