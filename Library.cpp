/**
 * @file Library.cpp
 * @author Gabbie Dement
 * @date 2026-04-04
 * @brief Implementation of the Library class method
 * 
 * contains the logic for list manipulation, searching, and file handling
 */

#include "Library.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Library::insert_sorted(Game g){
  list<Game>::iterator it;
  it = games.begin();
  
  while (it != games.end() && it->title < g.title){
    it++;
  }
  games.insert(it, g);
}

void Library::find_game(string substring){
  bool found = false;
  list<Game>::iterator it;
  
  for (it = games.begin(); it != games.end(); it++){
    if (it->title.find(substring) != string::npos){
      cout << "Found: " << it->title << " (" << it->year << ") by " << it->publisher << endl;
      found = true;
    }
  }
  if (!found){
    cout << "No matches found." << endl;
  }
}

void Library::find_genre(string genre){
  bool found = false;
  list<Game>::iterator it;
  
  for (it = games.begin(); it!=games.end(); it++){
    if (it->genre == genre){
      cout << "- " << it->title << " (" << it->year << ")" << endl;
      found = true;
    }
  }
  if (!found){
    cout << "No games in that genre found." << endl;
  }
}

void Library::remove_game(string title, int year){
  list<Game>::iterator it;
  it = games.begin();

  while (it != games.end()){
    if (it->title == title && it->year == year){
      it = games.erase(it);
    } else{
      it ++;
    }
  }
}

void Library::print_all(){
  list<Game>::iterator it;
  
  cout << left << setw(40) << "TITLE"
       << setw(25) << "PUBLISHER"
       << setw(20) << "GENRE"
       << setw(10) << "HOURS"
       << setw(10) << "PRICE"
       << "YEAR" << endl;
  cout << string(110, '-') << endl;
  
  for (it = games.begin(); it != games.end(); it++){
    cout << left << setw(40) << it->title
	 << setw(25) << it->publisher
	 << setw(20) << it->genre
	 << fixed << setprecision(1) << setw(10) << it->hoursPlayed
	 << "$" << setw(9) << fixed << setprecision(2) << it->price
	 << it->year << endl;
  }
}

void Library::load_from_file(string filename){
  ifstream fin(filename);
  if (!fin){
    return;
  }
  
  games.clear();
  Game temp;
  
  while (getline(fin, temp.title)){
    getline(fin, temp.publisher);
    getline(fin, temp.genre);
    fin >> temp.hoursPlayed >> temp.price >> temp.year;
    fin.ignore();
    games.push_back(temp);
  }
  fin.close();
}

void Library::store_to_file(string filename){
  ofstream fout(filename);
  list<Game>::iterator it;
  
  for (it = games.begin(); it != games.end(); it++){
    fout << it->title << "\n" << it->publisher << "\n" << it->genre << "\n"
	 << it->hoursPlayed << "\n" << it->price << "\n" << it->year << "\n";
  }
  fout.close();
}

void Library::push_front(Game g){
  games.push_front(g);
  games.sort();
}

void Library::push_back(Game g){
  games.push_back(g);
  games.sort();
}
