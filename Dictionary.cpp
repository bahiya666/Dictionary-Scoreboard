#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include "Dictionary.h"
#include "Tuple.h"
#include "Tuple.cpp"
#include <cstddef>

template<typename T, typename E>
Dictionary<T,E> :: Dictionary () : keys(NULL),values(NULL), currSize(0)
{}

template<typename T, typename E>
Dictionary<T,E> :: ~Dictionary ()
{
    if (keys!=NULL)
    {
        delete[] keys;
        keys = NULL;
    }

    if (values != NULL)
    {
        delete [] values;
        values = NULL;
    }

}

template<typename T, typename E>
void Dictionary<T,E> :: set(T key, E value)
{
        for (int i = 0; i < currSize ;  i++)
        {
            if (keys[i] == key)
            {
                values[i] = value;
                return;
            }
        }

        int ss = currSize +1;
        T* newKeys = new T[ss];
        E* newValues = new E[ss];

        for (int i = 0; i < currSize; i++) 
        {
            newKeys[i] = keys[i];
            newValues[i] = values[i];
                    
        }

        newKeys[currSize] = key;
        newValues[currSize] = value;

        if (keys!=NULL)
        {
            delete[] keys;
            keys = NULL;
        }

        if (values != NULL)
        {
            delete [] values;
            values = NULL;
        }

        keys = newKeys;
        values = newValues;
        currSize = ss;
        

    
}

template<typename T, typename E>
E Dictionary<T,E> :: at(T key)
{
    for (int i = 0; i < currSize; i++)
    {
        if (keys[i] == key)
        {
            return values[i];
        }
    }

    return E();
}

template<typename T, typename E>
void Dictionary<T, E>::removeAt(T key) 
{
    int index = -1;

    for (int i = 0; i < currSize; i++) 
    {
        if (keys[i] == key) 
        {
            index = i;
            break;
        }
    }

    if (index != -1) 
    {
        for (int i = index; i < currSize - 1; i++) 
        {
            keys[i] = keys[i + 1];
            values[i] = values[i + 1];
        }

        currSize--;

        T* newKeys = new T[currSize];
        E* newValues = new E[currSize];

        for (int i = 0; i < currSize; i++) 
        {
            newKeys[i] = keys[i];
            newValues[i] = values[i];
        }

        if (keys!=NULL)
        {
            delete[] keys;
            keys = NULL;
        }

        if (values != NULL)
        {
            delete [] values;
            values = NULL;
        }

        keys = newKeys;
        values = newValues;
    }

        if (currSize == 0) 
        {
            if (keys!=NULL)
            {
                delete[] keys;
                keys = NULL;
            }

            if (values != NULL)
            {
                delete [] values;
                values = NULL;
            }

        }
}

template<typename T, typename E>
void Dictionary<T,E> :: remove(E value) 
{
    int removeCount = 0;

    for (int i = 0; i < currSize; i++)
    {
        if (values[i] == value)
        {
            removeCount++;
        }
    }

    if (removeCount == 0)
    {
        return;
    }

    if (removeCount > 0)
    {
        T* newKeys = new T[currSize - removeCount];
        E* newValues = new E[currSize - removeCount];

        int newIndex = 0;

        for (int i = 0; i < currSize; i++)
        {
            if (values[i] != value)
            {
                newKeys[newIndex] = keys[i];
                newValues[newIndex] = values[i];
                newIndex++;
            }
        }

        if (keys!=NULL)
        {
            delete[] keys;
            keys = NULL;
        }      

        if (values != NULL)
        {
            delete [] values;
            values = NULL;
        }

        keys = newKeys;
        values = newValues;

        currSize -= removeCount;

        if (currSize == 0)
        {
            if (keys!=NULL)
            {
                delete[] keys;
                keys = NULL;
            }

            if (values != NULL)
            {
               delete [] values;
                values = NULL;
            }

        }
    }
}

template<typename T, typename E>
bool Dictionary<T,E> :: exists (T key)
{
    for (int i =0; i < currSize; i++)
    {
        if (keys[i]==key)
        {
            return true;
        }
    }
    return false;
}
   
template<typename T, typename E>
Tuple<int,T*> Dictionary<T,E> :: keysWithValue (E value)
{
    int count =0;

    for (int i=0; i< currSize; i++)
    {
        if (values[i]==value)
        {
            count ++;

        }
    }

    T* newMatchingKeys = new T[count];
    int c =0;

    for (int i = 0; i < currSize; i++)
    {
        if (values[i]==value)
        {
            newMatchingKeys[c] = keys[i];
            c++;
        }
    }

    Tuple<int, T*>r(count,newMatchingKeys);

    return r;

}

template<typename T, typename E>
void Dictionary<T,E> :: swap(T firstKey, T secondKey)
{
    int firstIndex = -1;
    int secondIndex = -1;

    for (int i = 0; i < currSize; i++)
    {
        if (keys[i] == firstKey)
        {
            firstIndex = i;
        }
        else if (keys[i] == secondKey)
        {
            secondIndex = i;
        }
    }

    if (firstIndex != -1 && secondIndex != -1)
    {
        E temp = values[firstIndex];
        values[firstIndex] = values[secondIndex];
        values[secondIndex] = temp;
    }
}

template<typename T, typename E>
void Dictionary<T,E> :: clear()
{
    if (keys != NULL)
    {
        delete[] keys;
        keys = NULL;
    }

    if (values != NULL)
    {
        delete[] values;
        values = NULL;
    }

    currSize = 0;
}

template<typename T, typename E>
T* Dictionary<T,E> :: getKeys()
{
    return keys;
}

template<typename T, typename E>
int Dictionary<T,E> :: size()
{
    return currSize;
}

#endif