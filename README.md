Overview:
This project provides a system for managing a dictionary of key-value pairs, as well as a scoreboard that tracks users' scores. The core data structures used in this project include Dictionary and ScoreBoard, both of which rely on the Tuple class to store key-value pairs. The Dictionary class offers various methods for adding, removing, and manipulating entries, while the ScoreBoard class is used to store and manage users' scores, including retrieving the highest scores.

Classes and Functionality:
1. Tuple Class (Tuple.h and Tuple.cpp)
  A generic class that stores two related values (firstValue and secondValue), which can be of any type.
  Methods:
  getFirst(): Returns the first value.
  getSecond(): Returns the second value.
  operator==: Compares two Tuple objects for equality.
2. Dictionary Class (Dictionary.h and Dictionary.cpp)
  A templated class that manages a collection of key-value pairs, where each key is of type T and each value is of type E.
  Provides various methods to manipulate the dictionary:
  set(T key, E value): Adds or updates a key-value pair.
  at(T key): Returns the value associated with the specified key.
  removeAt(T key): Removes a key-value pair based on the key.
  remove(E value): Removes key-value pairs with the specified value.
  exists(T key): Checks if a given key exists in the dictionary.
  keysWithValue(E value): Retrieves all keys associated with a specific value.
  swap(T firstKey, T secondKey): Swaps the values of two specified keys.
  clear(): Clears all entries in the dictionary.
  getKeys(): Returns a pointer to the array of keys.
  size(): Returns the number of entries in the dictionary.
3. ScoreBoard Class (ScoreBoard.h and ScoreBoard.cpp)
  A specialized version of the Dictionary class, where the dictionary stores user names as keys and their corresponding scores as values.
  Methods:
  addScore(std::string user, T score): Adds or updates a user's score.
  removeScore(std::string user): Removes a user's score.
  getScore(std::string user): Retrieves the score of a specified user.
  getHighScore(): Returns the highest score across all users.
  getHighScoreUser(): Returns a tuple containing the number of high scorers and their names.
Main Program (main.cpp):
  The main program demonstrates the use of the Tuple, Dictionary, and ScoreBoard classes. It performs several tests such as:
  Creating and printing Tuple objects.
  Using the Dictionary class to manage key-value pairs:
  Adding entries, checking for existence, retrieving values, removing entries, and clearing the dictionary.
  Managing users' scores using the ScoreBoard class:
  Adding, removing, and querying scores.
  Finding the highest score and displaying the users with the highest score.

Compilation and Running:
Prerequisites:
  A C++ compiler (e.g., GCC or Clang).
  C++11 or higher.
Instructions:
Download all the required source files (Dictionary.h, Dictionary.cpp, ScoreBoard.h, ScoreBoard.cpp, Tuple.h, Tuple.cpp, main.cpp).
Compile the files using a C++ compiler:
  g++ -o scoreboard main.cpp Dictionary.cpp ScoreBoard.cpp Tuple.cpp
Run the compiled program:
  ./scoreboard
  
Notes:
The program demonstrates basic dictionary and scoreboard functionality.
The Dictionary class supports operations like adding, updating, and removing key-value pairs.
The ScoreBoard class provides specific functionality for managing users' scores, including retrieving the highest score and the users with the highest score.
