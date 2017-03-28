#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
#include <limits>
#include <iomanip>
#include "cls.cpp"
#include <cmath>

using namespace std;

int main()
{
   double Ea = 0.506, Eb = 0.494, Sa, Sb;

   int K, Ra, Rb; 
   int j, h;
   Cls val; 

   ifstream inFile("infile", ios::in);
   ofstream outFile("outfile", ios::out);
	 
         inFile >> K >> Ra >> Rb;
         val.setval(Ra, Rb);

	 outFile << Ra << "\t" << Rb << endl;
         for(j=0;j<6;j++)
	 {
          
            for(h=0;h<j;h++)
            {
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');     
                break;
	    }
               inFile >> Sa;
               cout << Sa << endl;
	    if(Sa == 1.0)
            {
	       Sb = 0.0;
            }
            if(Sa == 0.5)
            {
               Sb = 0.5;
            }
	    if(Sa == 0.0)
            {
               Sb = 1.0;
            }
            outFile << setprecision(0) << fixed;
	    Ra = Ra + (K * (Sa - Ea));
	    Rb = Rb + (K * (Sb - Eb));
            val.setval(Ra, Rb);
            Ea = (1/(1+(pow(10, (Rb-Ra)/400))));
	    Eb = (1/(1+(pow(10, (Ra-Rb)/400))));
         outFile << val.getRa() << "\t" << val.getRb() << endl;
         }


return 0;
}
