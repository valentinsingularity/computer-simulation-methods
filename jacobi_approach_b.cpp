/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int i,j,n;
	double V[12][22],previous_V[12][22],change;
	ofstream fout("output.txt");
	
	for(i=0;i<=11;i++)
	  for(j=0;j<=21;j++)
	    if(i==0 || j==0 || i==11 || j==21) V[i][j]=1;
	    else V[i][j]=0;
	V[5][10]=V[5][11]=V[6][10]=V[6][11]=5;
	
	for(i=0;i<=11;i++)
	  for(j=0;j<=21;j++)
	    previous_V[i][j]=V[i][j];

    for(n=1;;n++)
    {
    	change=0;
    	for(i=1;i<=10;i++)
	      for(j=1;j<=20;j++)
	      {
	         V[i][j] = (previous_V[i+1][j]+previous_V[i-1][j]+previous_V[i][j+1]+previous_V[i][j-1])/4;
	         change+=  abs( (V[i][j]-previous_V[i][j])/V[i][j] );
	      }
	    for(i=1;i<=10;i++)
	      for(j=1;j<=20;j++)
	      	 previous_V[i][j]=V[i][j]; 
	      	 
	    if(change/200 <= 0.01)  // 1% accuracy achieved
	    {
	    	fout<<n<<" iterations"<<endl;
	    	for(i=1;i<=10;i++)
	    	{
	          for(j=1;j<=20;j++) fout<<V[i][j]<<" ";
			  fout<<endl;
		    }
	    	break;
	    }
		                     
    }
	  

	return 0;
}
