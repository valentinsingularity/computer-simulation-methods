/*
    The code can be compiled with any C/C++ compiler, like DevC++, Codeblocks, Mingw, etc.
    From the console, the code can be compiled with the command:  g++ -o euler_richardson euler_richardson.cpp  and afterwards it can be run with the command:  ./euler
    It should work on any teaching lab computer sice the language is the same as in professor Kinga Lipskoch's course Programming in C++. 
*/
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int N=100, tmax=200,i,t,nr_cars=54,p;
    int array[tmax+1][N], rule[8]={1,0,1,1,1,0,0,0}; // Rule 184 ~ 10111000 
	ofstream fout("output.txt");
	srand(time(0));
    
    for(i=51;i<=56;i++) array[0][i]=1; //traffic jam with 6 cars
    i=6;
    while(i<nr_cars)
	{
	   p=rand()%100;
	   if(p<50 || p>57)
	   {
	   	array[0][p]= 1;
	   	i++;
	   }	   
    }

    for(t=1;t<=tmax;t++)  //periodic boundary conditions
	{
		for(i=0;i<N;i++)
		{
			if(i==0)
			{
		    	if(array[t-1][N-1] ==1 && array[t-1][i]==1 && array[t-1][i+1]==1) array[t][i]=rule[0];
		    	else if(array[t-1][N-1]==1 && array[t-1][i]==1 && array[t-1][i+1]==0) array[t][i]=rule[1];
		    	else if(array[t-1][N-1]==1 && array[t-1][i]==0 && array[t-1][i+1]==1) array[t][i]=rule[2];
		    	else if(array[t-1][N-1]==1 && array[t-1][i]==0 && array[t-1][i+1]==0) array[t][i]=rule[3];
		    	else if(array[t-1][N-1]==0 && array[t-1][i]==1 && array[t-1][i+1]==1) array[t][i]=rule[4];
		    	else if(array[t-1][N-1]==0 && array[t-1][i]==1 && array[t-1][i+1]==0) array[t][i]=rule[5];
		    	else if(array[t-1][N-1]==0 && array[t-1][i]==0 && array[t-1][i+1]==1) array[t][i]=rule[6];
		    	else if(array[t-1][N-1]==0 && array[t-1][i]==0 && array[t-1][i+1]==0) array[t][i]=rule[7];
	    	}	
	        else if(i== N-1)
	        {
	        	if(array[t-1][i-1] ==1 && array[t-1][i]==1 && array[t-1][0]==1) array[t][i]=rule[0];
		    	else if(array[t-1][i-1]==1 && array[t-1][i]==1 && array[t-1][0]==0) array[t][i]=rule[1];
		    	else if(array[t-1][i-1]==1 && array[t-1][i]==0 && array[t-1][0]==1) array[t][i]=rule[2];
		    	else if(array[t-1][i-1]==1 && array[t-1][i]==0 && array[t-1][0]==0) array[t][i]=rule[3];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==1 && array[t-1][0]==1) array[t][i]=rule[4];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==1 && array[t-1][0]==0) array[t][i]=rule[5];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==0 && array[t-1][0]==1) array[t][i]=rule[6];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==0 && array[t-1][0]==0) array[t][i]=rule[7];
	        }
	        else
	        {
	        	if(array[t-1][i-1] ==1 && array[t-1][i]==1 && array[t-1][i+1]==1) array[t][i]=rule[0];
		    	else if(array[t-1][i-1]==1 && array[t-1][i]==1 && array[t-1][i+1]==0) array[t][i]=rule[1];
		    	else if(array[t-1][i-1]==1 && array[t-1][i]==0 && array[t-1][i+1]==1) array[t][i]=rule[2];
		    	else if(array[t-1][i-1]==1 && array[t-1][i]==0 && array[t-1][i+1]==0) array[t][i]=rule[3];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==1 && array[t-1][i+1]==1) array[t][i]=rule[4];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==1 && array[t-1][i+1]==0) array[t][i]=rule[5];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==0 && array[t-1][i+1]==1) array[t][i]=rule[6];
		    	else if(array[t-1][i-1]==0 && array[t-1][i]==0 && array[t-1][i+1]==0) array[t][i]=rule[7];
	        }
     	}
   }



    for(t=0;t<=tmax;t++)  //display
    {
       for(i=0;i<N;i++)
       {
       if(array[t][i]==1) fout<<'*';
       else fout<<' ';
       }
       fout<<endl;
    }
	
	
	return 0;
}
