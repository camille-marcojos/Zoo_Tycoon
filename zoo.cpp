/******************
 * Program: zoo.cpp
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description:
*******************/
#include <iostream>
#include <string>
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
#define MAXBAL 100000

Zoo::Zoo(){
    tCap = pCap = turtCap = 10;
    tigerCount = penguinCount = turtleCount = 0;
    balance = MAXBAL;
    profit = 0;
    tigers = new Animal*[10];
    penguins = new Animal*[10];
    turtles = new Animal*[10];

    for (int i = 0; i < 10; i++)
    {
        tigers[i] = NULL;
        penguins[i] = NULL;
        turtles[i] = NULL;
    }
}


void Zoo::startMenu()
{
    cout << "Welcome to Zoo Tycoon!" << endl;
    cout << "Press '1' to continue or" << endl;
    cout << "Press '2' to quit" << endl;
    cout << "Your input: ";
}

void Zoo::animalMenu(string& animal)
{
    cout << "You have a budget of " << "$" << balance << endl; 
    cout << "How many " << animal << " do you want to buy?" << endl;
    cout << "1. One" << endl;
    cout << "2. Two" << endl;
    cout << "Enter '1' or '2' for your selection." << endl;
    cout << "Your input: ";
}

int Zoo::getChoice()
{
    int choice;
    string input;    
    bool invalid = true;

    do
    {
        getline(cin,input);
        cout << endl;
        
        if(!input.empty())
        {
            if(is_int(input))
            {
                choice = stoi(input);
                if(choice == 1 || choice == 2)
                    invalid = false;
                else
                {
                    cout << "Not a valid choice." << endl;
                    cout << "Enter only 1 or 2." << endl;
                    cout << "Your input: ";
                    invalid = true; 
                }           
            }else
            {
                cout << "Not a valid choice." << endl;
                cout << "Enter only 1 or 2." << endl;
                cout << "Your input: ";
                invalid = true;      
            }
        }else {
            cout << "Enter only 1 or 2." << endl;
            cout << "Not a valid choice." << endl;
            cout << "Your input: ";
            invalid = true;             
        }

    }while(invalid);

    return choice;
}

int Zoo::threeChoices()
{
    int choice;
    string input;    
    bool invalid = true;

    do
    {
        getline(cin,input);
        cout << endl;
        
        if(!input.empty())
        {
            if(is_int(input))
            {
                choice = stoi(input);
                if(choice >= 1 || choice <= 3)
                    invalid = false;
                else
                {
                    cout << "Not a valid choice." << endl;
                    cout << "Enter only 1 or 2." << endl;
                    cout << "Your input: ";
                    invalid = true; 
                }           
            }else
            {
                cout << "Not a valid choice." << endl;
                cout << "Enter only 1 or 2." << endl;
                cout << "Your input: ";
                invalid = true;      
            }
        }else {
            cout << "Enter only 1 or 2." << endl;
            cout << "Not a valid choice." << endl;
            cout << "Your input: ";
            invalid = true;             
        }

    }while(invalid);

    return choice;
}

int Zoo::numAnimals()
{
    int number;
    string input;    
    bool invalid = true;

    do
    {
        getline(cin,input);
        cout << endl;

        if(!input.empty())
        {
            if(is_int(input))
            {
                number = stoi(input);
                if(number == 1 || number == 2)
                    invalid = false;
                else
                {
                    cout << "Not a valid option." << endl;
                    cout << "Enter only 1 or 2." << endl;
                    cout << "Your input: ";
                    invalid = true; 
                }           
            }else
            {
                cout << "Not a valid option." << endl;
                cout << "Enter only 1 or 2." << endl;
                cout << "Your input: ";
                invalid = true;      
            }
        }else{
            cout << "Not a valid option." << endl;
            cout << "Enter only 1 or 2." << endl;
            cout << "Your input: ";
            invalid = true;      
        }
    }while(invalid);

    return number;
}


bool Zoo::is_int(string choice)
{
    for(int i = 0; i < choice.size(); i++)
    {
        if(!isdigit(choice[i]))
            return false;
    }
    return true;
}

void Zoo::buyAnimal(int n, string& an){

    if(an == "tigers")
    {
        for(int i =0; i < n; i++)
        {
            tigers[i] = new Tiger(1,10000,1,5,.2);
            tigerCount++;
            balance -= (*tigers)->getCost();
        }    
    }else if(an == "penguins"){
        for(int i =0; i < n; i++)
        {
            penguins[i] = new Penguin(1,1000,5,1,.1);
            penguinCount++;
            balance -= (*penguins)->getCost();
        }    
    }else if(an == "turtles"){
        for(int i =0; i < n; i++)
        {
            turtles[i] = new Turtle(1,100,10,.5,.05);
            turtleCount++;
            balance -= (*turtles)->getCost();
        }    
    }
}

void Zoo::addAdultAnimal(string an){

    if(an == "tiger")
    {
        if(tigerCount == tCap){
            int dblSize = tCap * 2;
            Animal** tmpTiger = new Animal*[dblSize];

            for(int i = 0; i < tCap; i++)
            {
                tmpTiger[i] = NULL;
            }

            for(int i = 0; i < tigerCount; i++)
            {
                tmpTiger[i] = tigers[i];
            }

            delete[] tigers;
            tigers = tmpTiger;
            tCap = dblSize;
            tigers[tigerCount] = new Tiger(3,10000,1,5,.2);
            tigerCount++;
            balance -= (*tigers)->getCost();
        }else{
            tigers[tigerCount] = new Tiger(3,10000,1,5,.2);
            tigerCount++;
            balance -= (*tigers)->getCost();
        }    
    }else if(an == "penguin"){
        if(penguinCount == pCap){
            int dblSize = pCap * 2;
            Animal** tmpPeng = new Animal*[dblSize];

            for(int i = 0; i < pCap; i++)
            {
                tmpPeng[i] = NULL;
            }

            for(int i = 0; i < penguinCount; i++)
            {
                tmpPeng[i] = penguins[i];
            }

            delete[] penguins;
            penguins = tmpPeng;
            pCap = dblSize;
            penguins[penguinCount] = new Penguin(3,1000,5,1,.1);
            penguinCount++;
            balance -= (*penguins)->getCost();
        }else{
            penguins[tigerCount] = new Penguin(3,1000,5,1,.1);
            penguinCount++;
            balance -= (*penguins)->getCost();
        }  
    }else if(an == "turtle"){
        if(turtleCount == turtCap){
            int dblSize = turtCap * 2;
            Animal** tmpTurt = new Animal*[dblSize];

            for(int i = 0; i < turtCap; i++)
            {
                tmpTurt[i] = NULL;
            }

            for(int i = 0; i < turtleCount; i++)
            {
                tmpTurt[i] = turtles[i];
            }

            delete[] turtles;
            turtles = tmpTurt;
            turtCap = dblSize;
            turtles[turtleCount] = new Turtle(3,100,10,.5,.05);
            turtleCount++;
            balance -= (*turtles)->getCost();
        }else{
            turtles[turtleCount] = new Turtle(3,100,10,.5,.05);
            turtleCount++;
            balance -= (*turtles)->getCost();
        }  
    }
}

int Zoo::getTigerCount(){
    return tigerCount;
}

int Zoo::getPenguinCount(){
    return penguinCount;  
}

int Zoo::getTurtleCount(){
    return turtleCount;
}

void Zoo::setTigerCount(int x)
{
    tigerCount = x;
}
void Zoo::setPenguinCount(int x)
{
    penguinCount = x;
}
void Zoo::setTurtleCount(int x)
{
    turtleCount = x;
}
    

void Zoo::printTigers(){

    //cout << "in print tiger." << endl;
    for(unsigned int i = 0; i < tigerCount; i++)
    {
        int j =i;
        cout << "Tiger: " << ++j << " ";
        cout << tigers[i]->getAge() << " ";
        cout << tigers[i]->getCost() << " ";
        cout << tigers[i]->getBabies() << " ";
        cout << tigers[i]->getfoodCost() << " ";
        cout << tigers[i]->getPayoff() << " " << endl;
    }

}

void Zoo::printPenguins(){

    //cout << "in print penguin." << endl;
    for(unsigned int i = 0; i < penguinCount; i++)
    {
        int j =i;
        cout << "Penguin: " << ++j << " ";
        cout << penguins[i]->getCost() << " ";
        cout << penguins[i]->getBabies() << " ";
        cout << penguins[i]->getfoodCost() << " ";
        cout << penguins[i]->getPayoff() << " " << endl;
    }

}

void Zoo::printTurtles(){
    //cout << "in print turtle." << endl;
    for(unsigned int i = 0; i < turtleCount; i++)
    {
        int j =i;
        cout << "Turtle: " << ++j << " ";
        cout << turtles[i]->getCost() << " ";
        cout << turtles[i]->getBabies() << " ";
        cout << turtles[i]->getfoodCost() << " ";
        cout << turtles[i]->getPayoff() << " " << endl;
    }
}

void Zoo::ageAnimals(){
    int age;

    if(getTigerCount() == 0){
    }else{
        for(int i = 0; i < tigerCount; i++){
            age = tigers[i]->getAge();
            tigers[i]->setAge(age++);
            age = 0;
        }
    }

    if(getPenguinCount() == 0){
    } else{
        for(int i = 0; i < penguinCount; i++){
            age = penguins[i]->getAge();
            penguins[i]->setAge(age++);
            age = 0;
        }
    }

    if(getTurtleCount() == 0){
    } else{
        for(int i = 0; i < turtleCount; i++){
            age = turtles[i]->getAge();
            turtles[i]->setAge(age++);
            age = 0;
        }
    }
}


void Zoo::feedAnimals(){
    
    cout << "========== Feed Animals ==========" << endl;
    int expenses;
    int tigerFood = 0;
    int penguinFood = 0; 
    int turtleFood = 0;

    if(getTigerCount() == 0){
        cout << "There are no tigers to feed." << endl;
    } else{
        tigerFood = getTigerCount() * (*tigers)->getfoodCost();
    }

    if(getPenguinCount() == 0){
        cout << "There are no penguins to feed." << endl;
    } else{
        penguinFood = getPenguinCount() * (*penguins)->getfoodCost();
    }

    if(getTurtleCount() == 0){
        cout << "There are no turtles to feed." << endl;
    } else{
        turtleFood = getTurtleCount() * (*turtles)->getfoodCost();
    }

    expenses = tigerFood + penguinFood + turtleFood;
    cout << "Tiger food cost: " << tigerFood << endl;
    cout << "Penguin food cost: " << penguinFood << endl;
    cout << "Turtle food cost: " << turtleFood << endl;
    subFunds(expenses);

    cout << "Balance after feeding: " << balance << endl << endl;

}


void Zoo::BabyIsBorn(){

    int an = randNum(2);
    switch(an)
    {
        case 1:
            if(getTigerCount() == 0){
                cout << "You have no tigers in your zoo to give birth." << endl;
                break;
            } else{
                int adulttigs = adult(tigers);
                if(adulttigs == 0)
                {
                    cout << "There are no adult tigers to give birth." << endl;
                }else{
                    cout << "There are " << adulttigs << " adult tigers to give birth." << endl;
                    BabyTiger(adulttigs);
                }
            }
            break;
        case 2:
            if(getPenguinCount() == 0){
                cout << "You have no penguins in your zoo to give birth." << endl;
                break;
            } else{
                int adultpengs = adult(penguins);
                if(adultpengs == 0)
                {
                    cout << "There are no adult penguins to give birth." << endl;
                }else{
                    cout << "There are " << adultpengs << " adult penguins to give birth." << endl;
                    BabyPenguin(adultpengs);
                }
            }
            break;
        case 3: 
            if(getTurtleCount() == 0){
                cout << "You have no turtles in your zoo to give birth." << endl;
                break;
            } else{
                int adultturts = adult(penguins);
                if(adultturts == 0)
                {
                    cout << "There are no adult turtles to give birth." << endl;
                }else{
                    cout << "There are " << adultturts << " adult turtles to give birth." << endl;
                    BabyTurtle(adultturts);
                }
            }
            break;
        default:
            cout << "Invalid command.";
            break;
    }
}


void Zoo::BabyTiger(int numbabies){

    for(int i = 0; i < numbabies; i++){
        if(tigerCount == tCap){
            int dblSize = tCap * 2;
            Animal** tmpTiger = new Animal*[dblSize];

            for(int i = 0; i < tCap; i++)
            {
                tmpTiger[i] = NULL;
            }

            for(int i = 0; i < tigerCount; i++)
            {
                tmpTiger[i] = tigers[i];
            }

            delete[] tigers;
            tigers = tmpTiger;
            tCap = dblSize;
            tigers[tigerCount] = new Tiger(0,10000,1,5,.2);
            tigerCount++;
            
        }else{
            tigers[tigerCount] = new Tiger(0,10000,1,5,.2);
            tigerCount++;
        }
    }
}

void Zoo::BabyPenguin(int numbabies){

    for(int i = 0; i < numbabies; i++){
        if(penguinCount == pCap){
            int dblSize = pCap * 2;
            Animal** tmpPeng = new Animal*[dblSize];

            for(int i = 0; i < pCap; i++)
            {
                tmpPeng[i] = NULL;
            }

            for(int i = 0; i < penguinCount; i++)
            {
                tmpPeng[i] = penguins[i];
            }

            delete[] tigers;
            penguins = tmpPeng;
            pCap = dblSize;
            penguins[penguinCount] = new Penguin(0,10000,1,5,.2);
            penguinCount++;
            
        }else{
            penguins[penguinCount] = new Penguin(0,10000,1,5,.2);
            penguinCount++;
        }
    }
}

void Zoo::BabyTurtle(int numbabies){

    for(int i = 0; i < numbabies; i++){
        if(turtleCount == turtCap){
            int dblSize = turtCap * 2;
            Animal** tmpTurt = new Animal*[dblSize];

            for(int i = 0; i < turtCap; i++)
            {
                tmpTurt[i] = NULL;
            }

            for(int i = 0; i < turtleCount; i++)
            {
                tmpTurt[i] = turtles[i];
            }

            delete[] turtles;
            turtles = tmpTurt;
            turtCap = dblSize;
            turtles[turtleCount] = new Turtle(0,10000,1,5,.2);
            turtleCount++;
            
        }else{
            turtles[turtleCount] = new Turtle(0,10000,1,5,.2);
            turtleCount++;
        }
    }
}




int Zoo::adult(Animal**& an){

    int i = 0;
    int adults = 0;
    while(an[i] != NULL){

        if(an[i]->getAge() >= 3)
            adults++;
        
        i++;
    }

    return adults;
 
}


void Zoo::subFunds(int exp){
    balance -= exp;
}

int Zoo::randNum(int n){
    unsigned seed;
    seed = time(0);
    srand(seed);
    int num;

    if(n ==1)
    {
        num = rand() % 4 + 1;
        return num;
    }else if(n ==2)
    {
        num = rand() % 3 + 1;
        return num;

    }else if(n ==3)
    {
        num = rand() % (500 + 1 - 250) + 250;
        return num;
    }else
    {
        return 0;
    }
}

void Zoo::randEvent(){
    int event = randNum(1);

    cout << "========== Random Event ==========" << endl;
    switch(event)
    {
        case 1:
            sickAnimal();
            break;
        case 2:
            AttendanceBoom();
            break;
        case 3:
            BabyIsBorn();
            break;
        case 4:
            cout << "No random event happened." << endl;
            break;
        default:
            cout << "Invalid command." << endl;
    }
}


void Zoo::sickAnimal(){
    
    int an = randNum(2);
    switch(an)
    {
        case 1:
            if(getTigerCount() == 0){
                cout << "Oh no! There's a deadly tiger virus." << endl;
                cout << "You do not have any tigers to contract the virus." << endl;
                break;
            } else{
                TigerDied();
            }
            break;
        case 2:
            if(getPenguinCount() == 0){
                cout << "Oh no! There's a deadly penguin virus." << endl;
                cout << "You do not have any penguins to contract the virus." << endl;
                break;
            } else{
                PenguinDied();
            }
            break;
        case 3: 
            if(getTurtleCount() == 0){
                cout << "Oh no! There's a deadly turtle virus." << endl;
                cout << "You do not have any turtles to contract the virus." << endl;
                break;
            } else{
                TurtleDied();
            }
            break;
        default:
            cout << "Invalid command.";
            break;
    }
}

void Zoo::TigerDied() 
{
    int tigCount = getTigerCount();
    int newCount = 0;

    delete tigers[tigCount-1];
    tigers[tigCount-1] = NULL;
    newCount = --tigCount;
    setTigerCount(newCount);

    cout << "Oh no! One of your tigers died from a deadly tiger virus." << endl;
}

void Zoo::PenguinDied() 
{
    int pengCount = getPenguinCount();
    int newCount = 0;

    delete penguins[pengCount-1];
    penguins[pengCount-1] = NULL;
    newCount = --pengCount;
    setPenguinCount(newCount);

    cout << "Oh no! One of your penguins died from a deadly penguin virus." << endl;
}

void Zoo::TurtleDied() 
{
    int turCount = getTurtleCount();
    int newCount = 0;

    delete turtles[turCount-1];
    turtles[turCount-1] = NULL;
    newCount = --turCount;
    setTurtleCount(newCount);

    cout << "Oh no! One of your turtles died from a deadly turtle virus." << endl;
}

void Zoo::AttendanceBoom(){
    int rand = randNum(3);
    if(getTigerCount() != 0)
    {
        int bonus = rand * getTigerCount();
        profit += bonus;
        cout << "There was a boom in attendance! You earned an extra $" << bonus << endl;
        balance+= bonus;
    } else
    {
        cout << "There was a boom in attendance, but you have no tigers in the zoo for a bonus." << endl;
    }
}


void Zoo::buyAdultAnimal()
{
    int choice;

    cout << "Would you like to buy an adult animal?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Your input: ";
    choice = getChoice();

    if (choice == 1)
    {
        cout << "\nWhat type of animal would you like to buy?" << endl;
        cout << "1. Tiger" << endl;
        cout << "2. Penguin" << endl;
        cout << "3. Turtle" << endl;
        cout << "Your input: ";
        choice = threeChoices();

        switch (choice)
        {
            case 1:
                if (balance < 10000)
                {
                    cout << "You don't have enough money to buy a tiger." << endl;        
                }
                else
                {
                    addAdultAnimal("tiger");
                    cout << "Tiger cost: $10,000." << endl;
                    cout << "Balance: $" << balance << endl;
                }
                break;
            case 2:
                if (balance < 1000)
                {
                    cout << "You don't have enough money to buy a penguin." << endl;
                }
                else
                {
                    addAdultAnimal("penguin");
                    cout << "Penguin cost: $1,000" << endl;
                    cout << "Balance: $" << balance << endl;
                }
                break;
            case 3:
                if (balance < 100)
                {
                    cout << "You don't have enough money to buy a turtle." << endl;
                }
                else
                {
                    addAdultAnimal("turtle");
                    cout << "Turtle cost: $100." << endl;
                    cout << "Balance: $" << balance << endl;
                }
                break;
        default:
                cout << "Invalid operation." << endl;
                break;
        }
    }else
    {
        cout << "You chose to not buy an adult animal." << endl;
    }
}

void Zoo::payoff(){
    int tigerPayoff;
    int pengPayoff;
    int turtPayoff;

    tigerPayoff = getTigerCount() * 2000;
    pengPayoff = getPenguinCount() * 100;
    turtPayoff = getPenguinCount() * 5;

    profit = tigerPayoff+pengPayoff+turtPayoff;
    balance += profit;
    cout << "\n========== END OF DAY ==========" << endl;
    cout << "Profit for the day: $" << profit << endl;
    cout << "End of day balance: $" << balance << endl << endl;
}

void Zoo::replayMenu(){

    cout << "\nWould you like to replay?" << endl;
    cout << "Press '1' to continue or" << endl;
    cout << "Press '2' to quit" << endl;
    cout << "Your input: ";
}

bool Zoo::funds(){

    if(balance <= 0){

        cout << "You have no more money. Game is ending." << endl;
        return false;
    }else
    {
        return true;
    }
    
}


int Zoo::start()
{
    int replay;
    int day = 1;

    do{

        if(funds()){
            cout << "========== DAY " << day << " ==========" << endl;
            cout << "Budget for the day: $" << balance << endl;
            ageAnimals();
            feedAnimals();
            randEvent();
            payoff();
            buyAdultAnimal();
            replayMenu();
            replay = getChoice();
            day++;
        } else
        {
           replay = 2;
        }  
    } while(replay == 1);

    cout << "Game is quitting. Good bye." << endl;
    return 0;    
}

Zoo::~Zoo()
{
    int i = 0;
    while (tigers[i] != NULL)
    {
        delete tigers[i];
        i++;
    }

    i = 0;
    while (penguins[i] != NULL)
    {
        delete penguins[i];
        i++;
    }

    i = 0;
    while (turtles[i] != NULL)
    {
        delete turtles[i];
        i++;
    }

    delete [] tigers;
    delete [] penguins;
    delete [] turtles;
}
