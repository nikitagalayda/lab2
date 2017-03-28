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
   double Ra, Rb, Ea, Eb, Sa, Sb;

   int K; 
   int j, h;
   Cls val; 

   ifstream inFile("infile", ios::in);
   ofstream outFile("outfile", ios::out);
	 
         inFile >> K >> Ra >> Rb;
         val.setval(Ra, Rb);

	 outFile << Ra << "\t" << Rb << endl;
        
	 while (inFile >> Sa)
	 {
	   Sb = 1 - Sa;

            Ea = (1/(1+(pow(10, (Rb-Ra)/400))));
            Eb = (1/(1+(pow(10, (Ra-Rb)/400))));

            Ra = Ra + (K * (Sa - Ea));
            Rb = Rb + (K * (Sb - Eb));
            val.setval(Ra, Rb);
	    
	    outFile << setprecision(4) << val.getRa() << "\t" << val.getRb() << endl; 

	 }
return 0;
}
