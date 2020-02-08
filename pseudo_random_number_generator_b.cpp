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
	int i,j,k=20,N=10000,bin_lin_congr, bin_default;
	double chi_squared_lin_congr=0,chi_squared_default=0,histogram_lin_congr[21],histogram_default[21],rand_nr_lin_congr,rand_nr_default;
	ofstream fout("output.txt");
	srand(time(0));
    
    for(i=1;i<=N;i++)
    {
    	rand_nr_lin_congr = generate()/m;
		rand_nr_default = (double) rand() / (RAND_MAX);
		for(j=1;j<=k;j++) if(rand_nr_lin_congr >= (double)(j-1)/k && rand_nr_lin_congr < (double)j/k ) bin_lin_congr = j;
		for(j=1;j<=k;j++) if(rand_nr_default >= (double)(j-1)/k && rand_nr_default < (double)j/k ) bin_default = j;
		histogram_lin_congr[bin_lin_congr]++;
		histogram_default[bin_default]++;
    }
    
    for(i=1;i<=k;i++)
    {
    	chi_squared_lin_congr += (histogram_lin_congr[i] - N/k)*(histogram_lin_congr[i] - N/k)/(N/k);
		chi_squared_default += (histogram_default[i] - N/k)*(histogram_default[i] - N/k)/(N/k);
    }
    
    cout<<chi_squared_lin_congr/(k-1)<<endl<<chi_squared_default/(k-1)<<endl;
    

	return 0;
} 
