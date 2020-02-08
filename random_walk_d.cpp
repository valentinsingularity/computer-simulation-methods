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
	int i,j,N=1000,n=10000,x,x_final[10001],previous_step,v=1;
	// N- number of steps of a walk; n- number of trial walks; x - position; x_final[i] - final position(after N steps) of the trial walk i
	double alpha=0.75,x_average=0,x_squared_average=0,delta_x_squared,P_N[N+1],random_nr;
	//P_N[x] - probability that the molecule has moved a distance x in N steps	          	                                                                             
	ofstream fout("output.txt");
    srand(time(0));
    
    for(i=1;i<=N;i++) P_N[i]=0;
    

	for(i=1;i<=n;i++)  
	{
		//previous_step=1 for previous step changing the position by +v , previous_step=-1 for previous step changing the position by 0
		x=0;  //initial position at x=0
		previous_step=1; //initial direction of the walker(previous step changing the position by +v)
		
		for(j=1;j<=N;j++)
     	{
	    	random_nr = (double) rand() / (RAND_MAX);
	    	if(previous_step == 1)
	    	{
	    		if(random_nr <= alpha) //changes the position by +v
				{
					x+=v;
					previous_step=1;
				}  
	        	else //changes the position by 0
	        	{
	        		previous_step=-1;
	        	}
	    	}
	    	else if(previous_step == -1)
	    	{
	        	if(random_nr <= alpha) //changes the position by 0
				{
					previous_step=-1;
				}
	        	else //changes the position by +v
	        	{
	        		x+=v;
	        		previous_step=1;
	        	}
	    	}
	    }
	    x_final[i]=x;
	    P_N[x]+= (double) 1/n;
	}
	
	for(i=1;i<=n;i++) 
	{
		x_average += (double)x_final[i]/n;
		x_squared_average += (double) x_final[i]*x_final[i]/n;
	}
	
    delta_x_squared = x_squared_average - x_average*x_average;
    cout<<x_average<<"  "<<delta_x_squared<<endl;
    for(i=1;i<=N;i++) fout<<i<<"  "<<P_N[i]<<endl;  //output for plotting with Matlab
    
	return 0;
}
