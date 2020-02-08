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


int main()
{
	int i,j,N,n=10000,x,x_final[10001],l=1,previous_step;
	//N- number of steps of a walk; n- number of trial walks; x - position; l - step size ; x_final[i] - final position(after N steps) of the trial walk i
	double alpha=0.1,x_average=0,x_squared_average=0,delta_x_squared,random_nr;
	//l - step size;	          	                                                                             
	ofstream fout("output.txt");
    srand(time(0));
    
    
    for(N=1000;N<=5000;N+=10)
    {
    x_average=0;
	x_squared_average=0;
	for(i=1;i<=n;i++)  
	{
		//previous_step=1 for previous step to the right , previous_step=-1 for previous step to the left
		x=0;  //initial position at x=0
		previous_step=1; //initial direction of the walker to the right
		
		for(j=1;j<=N;j++)
     	{
	    	random_nr = (double) rand() / (RAND_MAX);
	    	if(previous_step == 1)
	    	{
	    		if(random_nr <= alpha) //jumps right
				{
					x+=l;
					previous_step=1;
				}  
	        	else //jumps left
	        	{
	        		x-=l;
	        		previous_step=-1;
	        	}
	    	}
	    	else if(previous_step == -1)
	    	{
	        	if(random_nr <= alpha) //jumps left
				{
					x-=l;
					previous_step=-1;
				}
	        	else //jumps right
	        	{
	        		x+=l;
	        		previous_step=1;
	        	}
	    	}
	    }
	    x_final[i]=x;
	}
	
	for(i=1;i<=n;i++) 
	{
		x_average += (double)x_final[i]/n;
		x_squared_average += (double) x_final[i]*x_final[i]/n;
	}
	
    delta_x_squared = x_squared_average - x_average*x_average;
    fout<<delta_x_squared<<"  "<<N<<endl;
    
   }


	return 0;
}
