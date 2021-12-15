/**
* \file		NumericStats.cpp
* \author	Priyank Maniya (s0534833)
* \date		10th, December 2021
* \todo		Define the constructor and member functions as required
**/
#include <fstream>
#include <vector>
#include <string>
#include "NumericStats.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>

/**
    * \constructor
    * \brief    Specifies the initial separating values
    * \param    low        maximum value for the low list
    * \param    medium    maximum value for the medium list
    **/
NumericStats::NumericStats(int low, int medium)
{
    lowVal = low;
    mediumVal = medium;
}

/**
    * \function    loadFromFileNamed()
    * \brief    Loads the integers found in the file into the three lists separated
    *            by the values specified in the constructor
    * \param    filename    string containing the name of the file to be loaded
    * \return    boolean        true if the file was found and processed; otherwise false
    * \postcondition        if successful lists are populated with numbers conforming to the ranges
    *                        if unsuccessful, no guarantees are provided
    **/
bool NumericStats::loadFromFileNamed(string filename)
{
    ifstream fStream;
    fStream.open(filename);
    if (fStream.is_open())
    {
        string Rows;
        while (getline(fStream, Rows))
        {
            stringstream ss;
            ss << Rows;
            string WoRd;
            while (ss >> WoRd)
            {
                if (stoi(WoRd) <= lowVal)
                {
                    lowList.push_back(stoi(WoRd));
                }
                else if (stoi(WoRd) <= mediumVal)
                {
                    midList.push_back(stoi(WoRd));
                }
                else
                {
                    highList.push_back(stoi(WoRd));
                }
                defaultList.push_back(stoi(WoRd));
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

/**
    * \function    resetRanges()
    * \brief    changes the separating values and adjusts the three lists as required
    *            ordering does not need to be maintained
    * \param    low        maximum value for the low list
    * \param    medium    maximum value for the medium list
    * \return    -none-
    * \postcondition    ranges are changed and list conform to the new ranges
    **/
void NumericStats::resetRanges(int low, int medium)
{
    ifstream fStream;
    lowList.clear();
    midList.clear();
    highList.clear();
    for (int i = 0; i < defaultList.size(); i++)
    {

        if (int(defaultList[i]) <= low)
        {
            lowList.push_back(defaultList[i]);
        }
        else if (int(defaultList[i]) <= medium)
        {
            midList.push_back(defaultList[i]);
        }
        else
        {
            highList.push_back(defaultList[i]);
        }
    }

}

/**
    * \function    clear()
    * \brief            empties all the lists in the object
    * \param            -none-
    * \return            -none-
    * \postcondition    ranges are unchanged, lists are empty
    **/
void NumericStats::clear()
{
    lowList.clear();
    midList.clear();
    highList.clear();
    defaultList.clear();
}

/**
    * \function getAverages()
    * \brief            determines the average value of each list
    * \param            array of doubles (one for each list)
    * \return            -none-
    * \postcondition    the array is populated with the averages of each of the three lists
    **/
void NumericStats::getAverages(double array[])
{
    double sum;
    for (int i = 0; i < lowList.size(); i++)
    {
        sum += lowList[i];
    }
    array[0] = sum / lowList.size();
    if (lowList.size() == 0)
    {
        array[0] = 0;
    }

    sum = 0.0;
    for (int i = 0; i < midList.size(); i++)
    {
        sum += midList[i];
    }
    array[1] = sum / midList.size();
    if (midList.size() == 0)
    {
        array[1] = 0;
    }

    sum = 0.0;
    for (int i = 0; i < highList.size(); i++)
    {
        sum += highList[i];
    }
    array[2] = sum / highList.size();
    if (highList.size() == 0)
    {
        array[2] = 0;
    }
}
