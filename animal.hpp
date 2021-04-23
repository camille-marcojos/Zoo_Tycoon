/******************
 * Program: animal.hpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{

    protected:
        double Age, Cost, Number_of_Babies, Base_Food_Cost, Payoff;
    public:
        Animal();
        Animal(double a, double c, double b);
        void setAge(double a);
        void setCost(double a);
        void setBabies(double a);
        virtual void setfoodCost(double f);
        virtual void setPayoff(double p);
        double getAge();
        double getCost();
        double getBabies();
        double getfoodCost();
        double getPayoff();
        virtual ~Animal();
};


#endif