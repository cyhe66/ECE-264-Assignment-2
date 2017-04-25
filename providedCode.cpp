// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2017

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds one string
class Data {
public:
  string data;
  Data(const string &s) { data = s; }
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l) {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    string line;
    getline(input, line);
    l.push_back(new Data(line));
  }

  input.close();
}

// Output the data to a specified input file
void writeDataList(const list<Data *> &l) {
  string filename;
  cout << "Enter name of output file: ";
  cin >> filename;

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->data << endl;
  }

  output.close();
}

void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  list<Data *> theList;
  loadDataList(theList);

  cout << "Data loaded.  Executing sort..." << endl;

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  writeDataList(theList);
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

void sortDataList(list<Data *> &l) {
	list<Data *>::const_iterator it =  l.begin();
	advance	(it, 3);
	num1 = stof(l,*it);	// gets a float from list
	advance (it,1)
	num2 = stof(l,*it);	// gets consecutive float from list
	advance (it,1)
	num3 = stof(l,*it);	//gets next consecutive float

	if( size < 102000){	//if true, it must be test case 1
	}
		//execute t1_sort		
	else if (num1<1000 and  num2<1000 and  num3<1000   ){	//if true, the numbers must be from test case 3  
		//execute t3_sort
	}
	else if( abs(num1 - num2) <= 1.0 and abs(num2 - num3) <= 1.0){ //if two instances of consecutive numbers
								    // are both within 1.0 of each other, then 
								    // must be test case 4
		//execute t4_sort
	}
	else 
		//execute t2_sort

}	

void t4_sort(list<Data *> &l) {
	int jpD, temp;

	for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++){
		jpD = ipD; // set the pointers equal
		while (jpD > l.begin() and jpD < *prev(jpD)){
			temp = jpD; 		// perform swap
			jpD = *prev(jpD);
			*prev(jpD) = temp;
			j--;			//check swap needed for next previous
		}
	}
}
 	

}		
		
  	// create 4 different sorting algorithms
  	// apply the algorithm to each sort
}



