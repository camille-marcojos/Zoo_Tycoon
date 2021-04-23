/******************
 * Program: Turtle.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#include "turtle.hpp"
#include "animal.hpp"

Turtle::Turtle() : Animal(){

}
Turtle::Turtle(double a, double c, double b, double f, double p) : Animal(a, c, b){
    setPayoff(p);
    setfoodCost(f);
}

void Turtle::setPayoff(double p){
    double percent = p;
    Payoff = Cost * percent;
}

void Turtle::setfoodCost(double f){
    Base_Food_Cost = 10 * f;
}


Turtle::~Turtle(){

}
