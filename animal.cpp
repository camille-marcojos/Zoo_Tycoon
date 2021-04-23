/******************
 * Program: animal.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#include "animal.hpp"



Animal::Animal(){
    Age = Cost = Number_of_Babies = Base_Food_Cost = Payoff = 0;
    
}

Animal::Animal(double a, double c, double b){
    Age = a;
    Cost = c;
    Number_of_Babies = b;
    Base_Food_Cost = 0;
    Payoff = 0;
}

void Animal::setAge(double a){
    Age = a;

}

void Animal::setCost(double c){
    Cost = c;

}

void Animal::setBabies(double b){
    Number_of_Babies = b;
    
}

void Animal::setfoodCost(double f){
    Base_Food_Cost = f;
}

void Animal::setPayoff(double p){
    Payoff = p;
    
}

double Animal::getAge(){
    return Age;
}

double Animal::getCost(){
    return Cost;
}

double Animal::getBabies(){
    return Number_of_Babies;
}

double Animal::getfoodCost(){
    return Base_Food_Cost;
}

double Animal::getPayoff(){
    return Payoff;
}

Animal::~Animal(){

}
