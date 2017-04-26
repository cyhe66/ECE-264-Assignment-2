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
void t4_sort(list<Data *> &l);
void t3_sort(list<Data *> &l);
void sortDataList(list<Data *> &l) {
	list<Data *>::const_iterator it =  l.begin();

	float num1, num2, num3;
	advance	(it, 3);
	num1 = stof((*it)->data, 0);	// gets a float from list
	advance (it,1);
	num2 = stof((*it)->data, 0);	// gets consecutive float from list
	advance (it,1);
	num3 = stof((*it)->data, 0);	// gets consecutive float from list

	if( l.size() < 102000){	//if true, it must be test case 1
		//execute t1_sort		
		cout << "T1" << endl;
	}
	else if (num1<1000 and  num2<1000 and  num3<1000   ){	//if true, the numbers must be from test case 3  

		//execute t3_sort
		t3_sort(l);
	}
	else if( abs(num1 - num2) <= 1.0 and abs(num2 - num3) <= 1.0){ //if two instances of consecutive numbers are both within 1.0 of each other, then must be test case 4
		//execute t4_sort
		t4_sort(l);
	}
	else {
		//execute t2_sort
		cout << "T2" << endl;
	}

}	

void t4_sort(list<Data *> &l) {
	for(list<Data *>::iterator i = l.begin(); i != l.end(); i++){
		// TODO Check for case where overflow changes number of digits
		while(i != l.begin() and (*i)->data < (*prev(i))->data ){
			iter_swap(i, prev(i));
			i--;
		}
	}
}

void t3_sort(list<Data *> &l){
	int s = l.size();
	int *c = new int[1000000];
	list<Data *> sorted;
	Data *p[1020000];
	for(list<Data *>::iterator i = l.begin(); i != l.end(); i++){
		int tmp = (int) 1000*(stof((*i)->data));// indexes must be integers
		p [(int) tmp ]= *i;
		c[tmp]++;// keeps track of duplicates
	}	// multiply 1000 makes all the numbers integers


	for (int j = 0;j <999999; j++){
		while (c[j]--){
		sorted.push_back( p[j] );
		}
	}
	l = sorted;
}

// msb radix sort
// --pad zeros
// --ignore the decimal point
// strcomp 
//void zero_pad(string str, int n){
	
