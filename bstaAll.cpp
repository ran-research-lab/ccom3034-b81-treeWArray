
#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

// These two defines allow you to print the value of any variable (whose type
// is overloaded for the operator<<). To use: define the DEBUG as true, and 
// put a _(x) in the code whenever you need to print a variable x. See the 
// example at http://ccom.uprrp.edu/~rarce/ccom3034/site/misc/template/

#define DEBUG false
#define _(x) {if (DEBUG) cout << "[Line:" << __LINE__ << "] " <<  #x << " = " << x << " " << endl;}

// A BST class implemented using static array

template <typename T, int CAPACITY>
class BSTA {
private: 
  T A[CAPACITY];
  bool valid[CAPACITY] ; 


  void recDisplay(ostream &out, int i, int dist) const;
  bool isValid(int i) const;

public:
  BSTA();
  bool search(const T &e) const;
  bool insert(const T &e);
  bool remove(const T &e);
  void display(ostream &out) const;

};

template <typename T, int CAPACITY>
ostream & operator<<(ostream &out, BSTA<T,CAPACITY> B) {
	B.display(out);
	return out;
}



// Implement the constructor. 
// Remember to initialize all elements of the valid array to false!

template<typename T, int CAPACITY>
BSTA<T,CAPACITY>::BSTA() {

}


// Given e, an element, search for it in the tree.
// Return true if found, false otherwise.

template<typename T, int CAPACITY>
bool BSTA<T,CAPACITY>::search(const T &e) const{
  return false;
}



// Given an element, insert it into tree if not already in the tree.
// If already in the tree, return false. Otherwise insert it and return 
// true.

template<typename T, int CAPACITY>
bool BSTA<T,CAPACITY>::insert(const T &e) {
  return false;
}



// Given an element, if found in the tree, remove it and return true.
// Otherwise return false.

template<typename T, int CAPACITY>
bool BSTA<T,CAPACITY>::remove(const T &e) {
  return false;
}


// Recursive display function, which is able to traverse
// all nodes of the BST

template<typename T, int CAPACITY>
void BSTA<T,CAPACITY>::recDisplay(ostream &out, int i, int dist) const{
	int cl = i << 1;
	int cr = cl + 1;

	// traverse to the right
	if (isValid(cr)) recDisplay(out, cr, dist + 1);

	// print this node
	for (int i = 0; i < dist; i++) cout << "    ";
	if (valid[i]) cout << A[i] << endl;

	// traverse to the left
	if (isValid(cl)) recDisplay(out, cl, dist + 1);
};


// Implementation of the display function which is called
// by the overloaded operator<<

template<typename T, int CAPACITY>
void BSTA<T,CAPACITY>::display(ostream &out) const {
	recDisplay(out, 1, 0);
};


// Given an index i returns true if the corresponding
// node is valid.
template<typename T, int CAPACITY>
bool BSTA<T,CAPACITY>::isValid(int i) const {
	return i < CAPACITY and valid[i];
}


using namespace std;


int main(int argc, char *argv[]) {

	BSTA<int,64> b;
	string inst; 
	int a;
	bool success;

	while (cin >> inst  and inst != "q") {
      
      if (inst == "i") {
        cin >> a;
        cout << "Inserting a " << a << ".\n";
        success = b.insert(a);
        cout << "  " << (success ? "Successfull" : "Failed") << " insertion.\n";
      }
      else if (inst == "r") {
        cin >> a;
        cout << "Removing the " << a << ".\n";
        success = b.remove(a);
        cout << "  " << (success ? "Successfull" : "Failed") << " removal.\n";
      }
      else if (inst == "s") {
        cin >> a;
        cout << "Searching for " << a << ".\n";
        success = b.search(a);
        cout << "  " << (success ? "Found" : "Not found") << "\n";
      }
      else if (inst == "d") {
        cout << endl << b << endl;

      }


      else {
        cout << "Not recongnized\n";      
      }    
	}
  	return 0;
   
}


