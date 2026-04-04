/**
 * @file main.cpp
 * @author Gabbie Dement
 * @date 2026-04-04
 * @brief the main driver for the game library program
 * 
 * the interface for users to interact with the library class and manage their game database
 */

#include <iostream>
#include <limits>
#include "Library.h"

using namespace std;

/**
 * makes sure the user enters a valid number
 *
 * @pre 
 * @return int valid int choice
 * @post 
 * 
 */
int get_valid_int();

int main(){
  Library myLib;
  int choice = -1;
  string filename;
  

  while (choice !=0){
    cout << "\n--- GAME DATABASE MANAGER ---\n"
	 << "1. Load Database\n2. Save Database\n"
	 << "3. Add Game\n4. Find Game\n"
	 << "5. Find Genre\n6. Remove Game\n"
	 << "7. Print Library\n8. Push Front\n9. Push Back\n"
	 << "0. Exit\n";
    choice = get_valid_int();

    if (choice == 1){
      cout << "Enter filename to load: ";
      getline(cin, filename);
      myLib.load_from_file(filename);
    }
    else if (choice == 2){
      cout << "Enter filename to store to: ";
      getline(cin, filename);
      myLib.store_to_file(filename);
    }
    else if (choice == 3 || choice == 8 || choice == 9){
      Game g;
      cout << "Title: ";
      getline(cin, g.title);

      cout << "Publisher: ";
      getline(cin, g.publisher);

      cout << "Genre: ";
      getline(cin, g.genre);

      cout << "Hours: ";
      cin >> g.hoursPlayed;

      cout << "Price: ";
      cin >> g.price;

      cout << "Year: ";
      cin >> g.year;

      if (choice == 3){
	myLib.insert_sorted(g);
      }
      else if (choice == 8){
	myLib.push_front(g);
      }
      else{
	myLib.push_back(g);
      }
    }
    else if (choice == 4){
      string search;
      cout << "Search title: ";
      getline(cin, search);
      myLib.find_game(search);
    }
    else if (choice == 5){
      string genre;
      cout << "Enter genre: ";
      getline(cin, genre);
      myLib.find_genre(genre);
    }
    else if (choice == 6){
      string title;
      int year;
      cout << "Title of game to remove: ";
      getline(cin, title);

      cout << "Year of release: ";
      cin >> year;
      myLib.remove_game(title, year);
    }
    else if (choice == 7){
      myLib.print_all();
    }
  }
  
  return 0;
}
        
int get_valid_int(){
  int input;
  while (!(cin >> input)){
    cout << "Invalid input. Please enter a valid number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //gives clean buffer

  return input;
}
