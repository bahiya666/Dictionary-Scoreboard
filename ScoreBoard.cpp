#ifndef SCORBOARD_CPP
#define SCORBOARD_CPP

#include <cstddef>

#include "Tuple.h"
#include "Tuple.cpp"

#include "Dictionary.h"
#include "Dictionary.cpp"

#include "ScoreBoard.h"

template<typename T>
ScoreBoard<T> :: ScoreBoard ()
{}

template<typename T>
ScoreBoard<T> :: ~ScoreBoard()
{}

template<typename T>
void ScoreBoard<T> :: addScore(std::string user, T score)
{
    if (scores.exists(user))
    {
        if (score > scores.at(user))
        {
            scores.set(user,score);
        }

        else 
        {
            scores.set(user,score);
        }
    }
   
}

template<typename T>
void ScoreBoard<T> :: removeScore (std::string user)
{
    if (scores.exists(user)) 
    {
        scores.removeAt(user);
    }
}

template<typename T>
T ScoreBoard<T> :: getScore(std::string user)
{
    if (scores.exists(user)) 
    {
        return scores.at(user);
    } 
    else 
    {
        return T(); 
    }
}

template<typename T>
T ScoreBoard<T> :: getHighScore()
{
    T highestScore = T();

    std::string* keys = scores.getKeys(); 
    int size = scores.size();
    
    for (int i = 0; i < size; i++) 
    {
        T currentScore = scores.at(keys[i]);
        if (currentScore > highestScore) 
        {
            highestScore = currentScore;
        }
    }
    
    delete[] keys; 
    return highestScore;
    
}

template<typename T>
Tuple<int,std::string*> ScoreBoard<T> :: getHighScoreUser()
{
    
    return scores.keysWithValue(getHighScore());
}


#endif