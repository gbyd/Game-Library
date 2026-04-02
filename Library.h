/**
 * @file Library.h
 * @author Gabbie Dement
 * @date 2026-04-02
 * @brief Header file for lib class
 * 
 * Declares the Library class. It manages a collection of games using a standard linked list.
 */

#indef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>
#include "Game.h"


/**
 * manages a list of games with sorted insertion and file I/O
 *
 * @class Library{ Library.h "game-lib/Library.h"
 * @brief a container class for the game database
 *
 */
class Library{
 private:
  std::list<Game> games; //linked list container

 public:

/**
 * goes through list to find the correct spot for the new game
 *
 * @param Game g the game to insert
 * @pre list must be either empty or already sorted
 * @return void 
 * @post the game is inserted and the list remains sorted by title
 * 
 */
  void insert_sorted(Game g);


/**
 * prints details for a game whose title contains the search string
 *
 * @param std::string substring the string to search for in the titles
 * @pre 
 * @return void 
 * @post matching games are printed
 * 
 */
  void find_game(std::string substring);


/**
 * goes through list and prints games matching the filtered genre
 *
 * @param std::string genre the genre to filter by
 * @pre 
 * @return void 
 * @post games matching the genre are printed
 * 
 */
  void find_genre(std::string genre);


/**
 * deletes game based on the exact title and release year
 *
 * @param std::string title the title of the game to remove
 * @param int year the release year of the game to remove
 * @pre 
 * @return void 
 * @post if a match is found, the game is removed from the list
 * 
 */
  void remove_game(std::string title, int year);


/**
 * prints all games in a formatted table
 *
 * @pre 
 * @return void 
 * @post prints the content of the library
 * 
 */
  void print_all();


/**
 * reads game data from text file and populates the list with that data
 *
 * @param std::string filename the path to the database file
 * @pre file needs to follow expected format and needs to exist
 * @return void 
 * @post list is cleared and replaced with file data
 * 
 */
  void load_from_file(std::string filename);


/**
 * writes all current list data to a text file
 *
 * @param std::string filename the path to save the file
 * @pre 
 * @return void 
 * @post data is written to a file. the file is either created or overwritten
 * 
 */
  void save_to_file(std::string filename);


/**
 * inserts game at the front
 *
 * @param Game g the game
 * @pre 
 * @return void 
 * @post game is added to the front and entire list is resorted alphabetically
 * 
 */
  void push_front(Game g);


/**
 * inserts game at the back
 *
 * @param Game g the game
 * @pre 
 * @return void 
 * @post game is added to the back and entire list is resorted alphabetically
 * 
 */
  void push_back (Game g);
};

#endif
