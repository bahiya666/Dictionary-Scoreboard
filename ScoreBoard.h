#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.cpp" 
#include "Tuple.h" 



template<typename T>
class ScoreBoard 
{
    private:
        Dictionary<std::string,T> scores;
    
    public:
        ScoreBoard();
        ~ScoreBoard();
        void addScore(std::string user, T score);
        void removeScore(std::string user);
        T getScore(std::string user);
        T getHighScore();
        Tuple<int,std::string*> getHighScoreUser();

};
#endif