#pragma once

#include <vector>
#include <string>
using namespace std;

// TODO - declare the class as required
class WordSplitter
{
public:
    WordSplitter(int num);
    bool loadFromFileNamed(string fileName);
    void reset();
    void resplit(int newSeprateFrom);
    void getShortStats(int array[]);

private:
    vector<string> shortLenghtList;
    vector<string> longLengthList;
    int seprateFrom = 0;
};