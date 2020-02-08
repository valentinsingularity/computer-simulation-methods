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
	int i,j,N=1000,n=10000,x,x_final[10001],l=1,previous_step;
	// N- number of steps of a walk; n- number of trial walks; x - position; l - step size ; x_final[i] - final position(after N steps) of the trial walk i
	double alpha=0.5,x_average=0,x_squared_average=0,delta_x_squared,P_N[2*N+1],random_nr;
	//l - step size; P_N[x+N] - probability that the final position of the jump is x (in N steps), x+N>=0	          	                                                                             
	ofstream fout("output.txt");
    srand(time(0));
    
    for(i=1;i<=2*N;i++) P_N[i]=0;
    

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
	    P_N[x+N]+= (double) 1/n;
	    cout<<x<<endl;
	}
	
	for(i=1;i<=n;i++) 
	{
		x_average += (double)x_final[i]/n;
		x_squared_average += (double) x_final[i]*x_final[i]/n;
	}
	
    delta_x_squared = x_squared_average - x_average*x_average;
    cout<<x_average<<"  "<<delta_x_squared<<endl;
    for(i=0;i<=2*N;i++) fout<<i-N<<"  "<<P_N[i]<<endl;  //output for plotting with Matlab
    
	return 0;
}
