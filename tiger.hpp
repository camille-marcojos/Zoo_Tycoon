/******************
 * Program: tiger.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#ifndef TIGER_H
#define TIGER_H
#include <string>
#include "animal.hpp"
using std::string;

class Tiger : public Animal{

    private:
    public: 
        Tiger();
        Tiger(double a, double c, double b, double f, double p);
        void setPayoff(double p);
        void setfoodCost(double f);
        ~Tiger();

};  

#endif
