/******************
 * Program: penguin.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#include "penguin.hpp"
#include "animal.hpp"

Penguin::Penguin() : Animal(){

}
Penguin::Penguin(double a, double c, double b, double f, double p) : Animal(a, c, b){
    setPayoff(p);
    setfoodCost(f);
}

void Penguin::setPayoff(double p){
    double percent = p;
    Payoff = Cost * percent;
}

void Penguin::setfoodCost(double f){
    Base_Food_Cost = 10 * f;
}


Penguin::~Penguin(){

}
