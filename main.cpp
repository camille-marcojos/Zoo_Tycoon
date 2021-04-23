/******************
 * Program: Project 2 - Zoo Game
 * Author: Camille Marcojos
 * Date: 10/20/19
 * Description: 
*******************/
#include <iostream>
#include "zoo.hpp"
#include "animal.hpp"
using std::cout;
using std::endl;


int main (){
    
   Zoo game;
   int choice;
   string t = "tigers", p = "penguins", turt = "turtles";
   int ntig, npeng, nturt;

   game.startMenu();
   choice = game.getChoice();
   cout << endl;

   if(choice == 1){
      game.animalMenu(t);
      ntig = game.numAnimals();
      game.buyAnimal(ntig, t); 
      cout << endl;

      game.animalMenu(p);
      npeng = game.numAnimals();
      game.buyAnimal(npeng, p); 
      cout << endl;

      game.animalMenu(turt);
      nturt = game.numAnimals();
      game.buyAnimal(nturt,turt); 
      cout << endl;
      
      game.start();
   } else{

      cout << "Game is quitting." << endl;
   }

   return 0;

}