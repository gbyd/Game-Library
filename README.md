Name: Gabrielle Dement
Date: 04/04/2026
Class: CSCI325 at UTM

--- Project Description: ---
This project implements a game library database using STL. It uses std::list to manage game data. You can add games, remove games, search for them, sort them alphabetically, load a file of games in, save a file of games, simply look at the data, and more.

--- Design Decisions: ---
- The insert_sorted method goes through the list using an iterator to find the correct place to put new entries alphabetically so that the list can remain sorted.
- The < operator was overloaded for easy comparisons.
- A multi line format is used to handle titles and publishers that contain spaces.
- The search feature is case sensitive.
- An example database file 'games_db.txt' is provided.

--- How to Run: ---
1. Type make to compile.
2. Run './game-lib'
3. Provide necessary inputs.
4. Run 'make clean' to remove objects and executables after exiting the programs.

