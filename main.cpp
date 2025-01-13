#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"

#include <iostream>

int main() {
    
    Tuple<int, std::string> tuple1(1, "One");
    Tuple<int, std::string> tuple2(2, "Two");

    // Test the getFirst and getSecond functions
    std::cout << "Tuple 1: First = " << tuple1.getFirst() << ", Second = " << tuple1.getSecond() << std::endl;
    std::cout << "Tuple 2: First = " << tuple2.getFirst() << ", Second = " << tuple2.getSecond() << std::endl;

    // Test the operator==
    if (tuple1 == tuple2) {
        std::cout << "Tuple 1 is equal to Tuple 2." << std::endl;
    } else {
        std::cout << "Tuple 1 is not equal to Tuple 2." << std::endl;
    }

    Tuple<int, std::string> tuple3(1, "One");

    if (tuple1 == tuple3) {
        std::cout << "Tuple 1 is equal to Tuple 3." << std::endl;
    } else {
        std::cout << "Tuple 1 is not equal to Tuple 3." << std::endl;
    }

     Dictionary<std::string, int> dictionary;

    // Add some key-value pairs
    dictionary.set("Alice", 42);
    dictionary.set("Bob", 99);
    dictionary.set("Eve", 78);

    // Check if keys exist
    std::cout << "Does 'Alice' exist? " << (dictionary.exists("Alice") ? "Yes" : "No") << std::endl;
    std::cout << "Does 'Charlie' exist? " << (dictionary.exists("Charlie") ? "Yes" : "No") << std::endl;

    // Get the value for a specific key
    std::cout << "Value for 'Bob': " << dictionary.at("Bob") << std::endl;

    // Get the keys with a specific value
    Tuple<int, std::string*> keysWith42 = dictionary.keysWithValue(42);
    std::cout << "Keys with value 42: ";
    for (int i = 0; i < keysWith42.getFirst(); i++) {
        std::cout << keysWith42.getSecond()[i] << " ";
    }
    std::cout << std::endl;

    // Remove a key-value pair
    dictionary.removeAt("Eve");

    // Check the size of the dictionary
    std::cout << "Dictionary size: " << dictionary.size() << std::endl;

    // Clear the dictionary
    dictionary.clear();
    std::cout << "Dictionary size after clear: " << dictionary.size() << std::endl;

    ScoreBoard<int> scoreBoard;

    // Add scores for some users
    scoreBoard.addScore("User1", 100);
    scoreBoard.addScore("User2", 150);
    scoreBoard.addScore("User3", 120);

    // Test getScore function
    std::cout << "User1's score: " << scoreBoard.getScore("User1") << std::endl;
    std::cout << "User2's score: " << scoreBoard.getScore("User2") << std::endl;

    // Test getHighScore function
    std::cout << "Highest Score: " << scoreBoard.getHighScore() << std::endl;

    // Test getHighScoreUser function
    Tuple<int, std::string*> highScorers = scoreBoard.getHighScoreUser();
    std::cout << "Number of High Scorers: " << highScorers.getFirst() << std::endl;
    std::cout << "High Scorers: ";
    for (int i = 0; i < highScorers.getFirst(); i++) {
        std::cout << highScorers.getSecond()[i] << " ";
    }
    std::cout << std::endl;

    // Remove a user's score
    scoreBoard.removeScore("User2");

    // Test getHighScoreUser function again
    highScorers = scoreBoard.getHighScoreUser();
    std::cout << "Number of High Scorers: " << highScorers.getFirst() << std::endl;
    std::cout << "High Scorers: ";
    for (int i = 0; i < highScorers.getFirst(); i++) 
    {
        std::cout << highScorers.getSecond()[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
