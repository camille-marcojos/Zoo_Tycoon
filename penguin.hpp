/******************
 * Program: Penguin.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#ifndef PENGUIN_H
#define PENGUIN_H
#include <string>
#include "animal.hpp"
using std::string;

class Penguin : public Animal{

    private:
    public: 
        Penguin();
        Penguin(double a, double c, double b, double f, double p);
        void setPayoff(double p);
        void setfoodCost(double f);
        ~Penguin();

};  

#endif
