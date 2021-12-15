#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "WordSplitter.h"

using namespace std;
// hint - to remove an element from a vector
// myVector is the vector object - pos is the index location that you wish to remove
//
// myVector.erase(myVector.begin()+pos);

// TODO - define the constructor and member functions as required
WordSplitter::WordSplitter(int num)
{
    seprateFrom = num;
}


bool WordSplitter::loadFromFileNamed(string fileName)
{
    seprateFrom = 3;
    ifstream fStream;
    fStream.open(fileName);
    if (fStream.is_open())
    {
        string rows;
        while (getline(fStream, rows))
        {
            stringstream ss;
            string word;
            ss << rows;
            while (ss >> word)
            {
                if (word.length() <= seprateFrom)
                {
                    shortLenghtList.push_back(word);
                }
                else
                {
                    longLengthList.push_back(word);
                }
            }
        }
        fStream.close();
        return true;
    }
    else
    {
        return false;
    }
}

void WordSplitter::reset()
{

    shortLenghtList.clear();
    longLengthList.clear();
}

void WordSplitter::resplit(int newSeprateFrom)
{
    vector<string> tempList ;
    tempList.insert(tempList.begin(), shortLenghtList.begin(), shortLenghtList.end());
    tempList.insert(tempList.end(), longLengthList.begin(), longLengthList.end());
    reset();
    cout << tempList.size() << endl;
    for (unsigned i=0; i < tempList.size(); i++)
    {
        if (tempList[i].length() <= newSeprateFrom)
        {
            shortLenghtList.push_back(tempList[i]);
        }
        else
        {
            longLengthList.push_back(tempList[i]);
        }
    }
}

void WordSplitter::getShortStats(int array[])
{
    int wordLength = 0;
    array[0] = shortLenghtList.size();
   
      for (int j = 0; j < shortLenghtList.size(); j++)
    {   
        if (j == 0)
        {
            wordLength = shortLenghtList[j].length();
        }
        else if (shortLenghtList[j].length() < wordLength)
        {
            wordLength = shortLenghtList[j].length();
        }
    }
    
    array[1] = wordLength;
    wordLength = 0;
    
    for (int j = 0; j < shortLenghtList.size(); j++)
    {   
        if (j == 0)
        {
            wordLength = shortLenghtList[j].length();
        }
        else if (shortLenghtList[j].length() > wordLength)
        {
            wordLength = shortLenghtList[j].length();
        }
    }
    
    array[2] = wordLength;
}