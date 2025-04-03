//include any standard libraries needed
using namespace std;

#include <iostream>
#include <fstream>


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double arr[], int arrSize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double arr[], int &arrSize, int idx);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double arr[], int arrSize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {

   // verify file name provided on command line

   string fileName;

   ifstream inFS;

      if(argc < 2)
      {
         cout << "Enter file on command line" << endl;
         exit(1);
      }
      if(argc > 2)
      {
         cout << "Too many arguments, one file allowed" << endl;
         exit(1);
      }
      fileName = argv[1]; 

   // open file and verify it opened

   inFS.open(fileName);

   if(!inFS.is_open())
   {

      cout << fileName << " did not open" << endl;
      exit(1);

   }

   // Declare an array of doubles of size ARR_CAP.

   double arr[ARR_CAP];
   double temp;
   int i = 0;
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

   while(inFS >> temp)
   {

      arr[i] = temp;
      i++;

   }
    
   // Call the mean function passing it this array and output the 
   // value returned.

   cout << "Mean: " << mean(arr, i) << endl << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.

   // Call the remove function to remove the value at the index provided by the user.

   int rmv;

   cout << "Enter index of value to be removed (0 to " << i-1 << "):" << endl << endl; 

   cin >> rmv;


	
   // Call the display function to output the array.

   cout << "Before removing value: ";
   display(arr, i);
   cout << endl << endl;
    
   // Call the display function again to output the array
   // with the value removed.

   remove(arr, i, rmv);
   cout << "After removing value: ";
   display(arr, i);
   cout << endl << endl;
   
   // Call the mean function again to get the new mean

   cout << "Mean: " << mean(arr, i);
   
	return 0;
}

double mean(const double arr[], int arrSize)
{

   double sum = 0;

   for(int i = 0; i < arrSize; i++)
   {

      sum = sum + arr[i];

   }

   return sum/arrSize;

}

void remove(double arr[], int &arrSize, int idx)
{

   if(arrSize <= idx || idx < 0)
   {

      return;

   }

   for(int i = idx; i < arrSize-1; i++)
   {

      arr[i] = arr[i+1];

   }

   arrSize--;

}

void display(const double arr[], int arrSize)
{

   for(int i = 0; i < arrSize - 1; i++)
   {

      cout << arr[i] << ", ";

   }

   cout << arr[arrSize-1];

}