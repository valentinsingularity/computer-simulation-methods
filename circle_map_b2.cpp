/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <cmath>
using namespace std;



int main()
{
	int i,m=10000;   // m->infinity
	double theta,omega,K=0.5,W[1001],delta_theta;  // 0<theta<1 - polar angle; W - winding number; omega - frequency ratio; K - strenght of nonlinear coupling
	ofstream fout("output.txt");
	
	for(K=0.01;K<=1;K+=0.01)
	{
	   for(omega=0.001;omega<=1;omega+=0.001)
	   {   
	    	theta=0.2,W[(int)(omega*1000)]=0;
		    for(i=0;i<m;i++)
	        {
     		   delta_theta=omega-(K/2*M_PI)*sin((2*M_PI*theta)*M_PI/180);  // 2*M_PI*theta - angle in degrees ; *M_PI/180 - converts to radians
	    	   W[(int)(omega*1000)]=delta_theta/m;
		       theta+=delta_theta;
	    	   if(theta>=1) theta-=1; // modulo 1
	        }
	   }
	   for(i=1;i<=990;i++)
		  if( (W[i] >= (W[i+10]-0.00000001) ) && (W[i] <= (W[i+10]+0.00000001) ) )  
			{
				omega=(double) i/1000;
				fout<<omega<<" "<<K<<endl;
				fout<<omega+0.01<<" "<<K<<endl;
			}
	}
	
	
	return 0;
}
