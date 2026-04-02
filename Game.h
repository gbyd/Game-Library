/**
 * @file Game.h
 * @author Gabbie Dement
 * @date 2026-04-02
 * @brief Header file for game structure
 * 
 * Defines the data structure used to store info about video games.
 */

#indef GAME_H
#define GAME_H

#include <string>

//a struct that contains any data about the game
struct Game{
  std::string title; 
  std::string publisher;
  std::string genre;
  float hoursPlayed; //total amount of hours played
  float price; //non-sale price
  int year; //year game was released



/**
 * overloaded less than operator to compare two games alphabetically by their titles
 *
 * @param const Game& other The game that's being compared
 * @pre 'other' needs to be a valid game obj
 * @return bool True if the title comes before 'other' alphabetically
 * @post 
 * 
 */
  bool operator<(const Game& other) const{
    return title < other.title;
  }
};

#endif
