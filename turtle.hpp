/******************
 * Program: Turtle.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#ifndef TURTLE_H
#define TURTLE_H
#include <string>
#include "animal.hpp"
using std::string;

class Turtle : public Animal{

    private:
    public: 
        Turtle();
        Turtle(double a, double c, double b, double f, double p);
        void setPayoff(double p);
        void setfoodCost(double f);
        ~Turtle();

};  

#endif
