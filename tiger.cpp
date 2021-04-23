/******************
 * Program: tiger.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#include "tiger.hpp"
#include "animal.hpp"

Tiger::Tiger() : Animal(){

}
Tiger::Tiger(double a, double c, double b, double f, double p) : Animal(a, c, b){
    setPayoff(p);
    setfoodCost(f);
}

void Tiger::setPayoff(double p){
    double percent = p;
    Payoff = Cost * percent;
}

void Tiger::setfoodCost(double f){
    Base_Food_Cost = 10 * f;
}


Tiger::~Tiger(){

}
