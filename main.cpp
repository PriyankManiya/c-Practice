#include <iostream>
#include <string>
#include "WordSplitter.h"

using namespace std;

int main() {
WordSplitter document(8); // define our ADT
string fileName;
bool found;

cout << "File name to process: ";
cin >> fileName;

// TODO - loop until we have load a file
found = document.loadFromFileNamed(fileName); // have it load the data


//TODO - retrieve the statistics for the short word list
// and display the information in a clear manner
// define array to store data and call the function to fill the data
int array[3] = { 0,0,0 };
document.getShortStats(array);


//TODO - display the data returned clearly
    cout << "Number of words in the first list: "<< array[0] << endl;
    cout << "Length of smallest word in the first list: " << array[1] << endl;
    cout << "Length of longest word in the first list: " << array[2] << endl;




//TODO - change the separating value and redisplay the short list statistics
// use the member function resplit
document.resplit(8);




return 0;
}