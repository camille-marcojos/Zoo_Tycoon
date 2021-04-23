/******************
 * Program: Zoo class
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#ifndef ZOO_H
#define ZOO_H
#include <string>
#include "animal.hpp"
using std::string;

class Zoo
{
    private:
        int tCap, pCap, turtCap;
        Animal** tigers;
        Animal** penguins;
        Animal** turtles;
        int tigerCount, penguinCount, turtleCount;
        int balance;
        int profit;
    public:
        Zoo();
        int start();
        int getChoice();
        void animalMenu(string& animal);
        int numAnimals();
        void startMenu();
        bool is_int(string choice);
        void buyAnimal(int n, string &);
        void BabyTiger(int numbabies);
        void BabyPenguin(int numbabies);
        void BabyTurtle(int numbabies);
        int getTigerCount();
        int getPenguinCount();
        int getTurtleCount();
        void setTigerCount(int x);
        void setPenguinCount(int x);
        void setTurtleCount(int x);
        void printTigers();
        void printPenguins();
        void printTurtles();
        void ageAnimals();
        void BabyIsBorn();
        int adult(Animal**& an);
        void TigerDied();
        void PenguinDied();
        void TurtleDied();
        void feedAnimals();
        void subFunds(int expenses);
        int randNum(int n);
        void randEvent();
        void sickAnimal();
        void AttendanceBoom();
        void buyAdultAnimal();
        int threeChoices();
        void addAdultAnimal(string);
        void payoff();
        void replayMenu();
        bool funds();
        ~Zoo();


};

#endif