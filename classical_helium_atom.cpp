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
	int i;
	ofstream fout("output.txt");
	double r1_x=1.45, r1_y=0, r2_x=-1, r2_y=0, v1_x=0, v1_y=0.9, v2_x=0, v2_y=-1, a1_x, a1_y, a2_x, a2_y;
	double r1, r2, r12, r1_mid, r2_mid, r12_mid, r1_x_mid, r1_y_mid, r2_x_mid, r2_y_mid, v1_x_mid, v1_y_mid, v2_x_mid, v2_y_mid, a1_x_mid, a1_y_mid, a2_x_mid, a2_y_mid, E, E_0, E1,E1_mid; //parameters
	double delta = 0.0001;
	
	E_0 = 0.5*(v1_x*v1_x+v1_y*v1_y+v2_x*v2_x+v2_y*v2_y) -2/(sqrt(r1_x*r1_x+r1_y*r1_y)) -2/(sqrt(r2_x*r2_x+r2_y*r2_y)) + 1/(sqrt( (r1_x-r2_x)*(r1_x-r2_x) + (r1_y-r2_y)*(r1_y-r2_y) ) ); //initial energy
	
	for(i=1;i<=500000;i++)
	{	
	   r1=sqrt(r1_x*r1_x+r1_y*r1_y); //distance of the first electron to the nucleus
	   r2=sqrt(r2_x*r2_x+r2_y*r2_y); //distance of the second elctron to the nucleus
	   r12=sqrt( (r1_x-r2_x)*(r1_x-r2_x) + (r1_y-r2_y)*(r1_y-r2_y) ); //distance between the electrons
	   a1_x = -2*r1_x/(r1*r1*r1) + (r1_x-r2_x)/(r12*r12*r12);   //equations of motion
	   a1_y = -2*r1_y/(r1*r1*r1) + (r1_y-r2_y)/(r12*r12*r12);
	   a2_x = -2*r2_x/(r2*r2*r2) + (r2_x-r1_x)/(r12*r12*r12);
	   a2_y = -2*r2_y/(r2*r2*r2) + (r2_y-r1_y)/(r12*r12*r12);
	   
	   r1_x_mid = r1_x + 0.5*v1_x*delta;  //implementation of the Euler-Richardson algortihm
	   r1_y_mid = r1_y + 0.5*v1_y*delta;
	   r2_x_mid = r2_x + 0.5*v2_x*delta;
	   r2_y_mid = r2_y + 0.5*v2_y*delta;
	   v1_x_mid = v1_x + 0.5*a1_x*delta;
	   v1_y_mid = v1_y + 0.5*a1_y*delta;
	   v2_x_mid = v2_x + 0.5*a2_x*delta;
	   v2_y_mid = v2_y + 0.5*a2_y*delta;
	   
	   r1_mid=sqrt(r1_x_mid*r1_x_mid+r1_y_mid*r1_y_mid);
	   r2_mid=sqrt(r2_x_mid*r2_x_mid+r2_y_mid*r2_y_mid);
	   r12_mid=sqrt( (r1_x_mid-r2_x_mid)*(r1_x_mid-r2_x_mid) + (r1_y_mid-r2_y_mid)*(r1_y_mid-r2_y_mid) );
	   a1_x_mid = -2*r1_x_mid/(r1_mid*r1_mid*r1_mid) + (r1_x_mid-r2_x_mid)/(r12_mid*r12_mid*r12_mid);
	   a1_y_mid = -2*r1_y_mid/(r1_mid*r1_mid*r1_mid) + (r1_y_mid-r2_y_mid)/(r12_mid*r12_mid*r12_mid);
	   a2_x_mid = -2*r2_x_mid/(r2_mid*r2_mid*r2_mid) + (r2_x_mid-r1_x_mid)/(r12_mid*r12_mid*r12_mid);
	   a2_y_mid = -2*r2_y_mid/(r2_mid*r2_mid*r2_mid) + (r2_y_mid-r1_y_mid)/(r12_mid*r12_mid*r12_mid);
	   
	   r1_x = r1_x + v1_x_mid*delta;
	   r1_y = r1_y + v1_y_mid*delta;
	   r2_x = r2_x + v2_x_mid*delta;
	   r2_y = r2_y + v2_y_mid*delta;
	   v1_x = v1_x + a1_x_mid*delta;
	   v1_y = v1_y + a1_y_mid*delta;
	   v2_x = v2_x + a2_x_mid*delta;
	   v2_y = v2_y + a2_y_mid*delta;
	   
	   E = 0.5*(v1_x*v1_x+v1_y*v1_y+v2_x*v2_x+v2_y*v2_y) -2/(sqrt(r1_x*r1_x+r1_y*r1_y)) -2/(sqrt(r2_x*r2_x+r2_y*r2_y)) + 1/(sqrt( (r1_x-r2_x)*(r1_x-r2_x) + (r1_y-r2_y)*(r1_y-r2_y) ) );  //compute the energy at this step
	   if(E<0.9*E_0 || E> 1.1*E_0) //check for the energy conservation
	   
	   fout<<r1_x<<" "<<r1_y<<" "<<r2_x<<" "<<r2_y<<endl;  //prints the results in file for plotting with matlab  
	   
/*	   E1=0.5*(v1_x*v1_x+v1_y*v1_y) -2/(sqrt(r1_x*r1_x+r1_y*r1_y)) + 1/(sqrt( (r1_x-r2_x)*(r1_x-r2_x) + (r1_y-r2_y)*(r1_y-r2_y) ) );
	   E1_mid=0.5*(v1_x_mid*v1_x_mid+v1_y_mid*v1_y_mid) -2/(sqrt(r1_x_mid*r1_x_mid+r1_y_mid*r1_y_mid)) + 1/(sqrt( (r1_x_mid-r2_x_mid)*(r1_x_mid-r2_x_mid) + (r1_y_mid-r2_y_mid)*(r1_y_mid-r2_y_mid) ) );  
	   if(abs(E1-E1_mid)>0.1*E1_mid) delta=delta/2;  //time-step control
	   else if(abs(E1-E1_mid)<0.001*E1_mid) delta=2*delta;  */
	   
    }
	
	
	
	return 0;
}
