#include "cls.h"

      int Cls::getK()
         {
	    return K; 
	 }   

      double Cls::getRa()
         {
            return Ra;
	 } 
      
      double Cls::getRb()
         {
            return Rb;
	 }

      void Cls::setval(double x, double y)
         {
	    Ra = x;
	    Rb = y;
	 }

