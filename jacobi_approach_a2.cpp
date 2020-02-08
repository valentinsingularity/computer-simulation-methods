/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

double exact_form_V(double x, double y)
{
	return (10.5-x)*(10.5-x)*(5.5-y)*(5.5-y)/(5.5*5.5*10.5*10.5);
}

double exact_form_V_2(double x, double y)
{
	return x+y;
}

double exact_form_V_3(double x, double y)
{
	return x*y;
}

double exact_form_V_4(double x, double y)
{
	return 5*(x-2*y)+x*x-y*y*y;
}


int main()
{
	int i,j,n;
	double V[7][12],previous_V[7][12],change;
	ofstream fout("output.txt");
	
	for(i=0;i<=6;i++)
	  for(j=0;j<=11;j++)
	    if(i==0 || j==0 || i==6 || j==11) V[i][j]=1;
		else V[i][j]= 0.7 * exact_form_V(j,i); 
		
	for(i=0;i<=6;i++)
	      for(j=0;j<=11;j++)
	         previous_V[i][j]=V[i][j];	

    for(n=1;;n++)
    {
    	change=0;
    	for(i=1;i<=5;i++)
	      for(j=1;j<=10;j++)
	      {
	         V[i][j] = (previous_V[i+1][j]+previous_V[i-1][j]+previous_V[i][j+1]+previous_V[i][j-1])/4;
	         change+=  abs( (V[i][j]-previous_V[i][j])/V[i][j] );
	      }
	    for(i=1;i<=5;i++)
	      for(j=1;j<=10;j++)
	      	 previous_V[i][j]=V[i][j];  
			     
	    if(change/200 <= 0.01)  // 1% accuracy achieved
	    {
	    	fout<<n<<" iterations"<<endl;
	    	for(i=1;i<=5;i++)
	    	{
	          for(j=1;j<=10;j++) fout<<V[i][j]<<" ";
			  fout<<endl;
		    }
	    	break;
	    }
		                     
    }
	  

	return 0;
}
