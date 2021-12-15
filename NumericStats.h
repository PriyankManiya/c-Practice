/**
* \file		NumericStats.h
* \author	Priyank Maniya (s0534833)
* \date		10th, December 2021	
* \todo		declare the class as required int he assignment
**/
#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class NumericStats
{
public:
    NumericStats(int low, int medium);       // Constructor
    bool loadFromFileNamed(string filename); // Loads the integers found in the file into the three lists separated by the values specified in the constructor
    void resetRanges(int low, int medium);   // changes the separating values and adjusts the three lists as required ordering does not need to be maintained
    void clear();                            // empties all the lists in the object
    void getAverages(double array[]);        // determines the average value of each list

private:
    int lowVal;              // will save the low value of given bound
    int mediumVal;           // will save the medium value of given bound
    vector<int> lowList;     // will save the integers which are lower than the low bound
    vector<int> midList;     // will save the integers which are lower than the medium bound
    vector<int> highList;    // will save the integers which are greater than the medium bound
    vector<int> defaultList; // will save (for spare ) the all integers which program will get from orignal file
};
