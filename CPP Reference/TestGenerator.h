#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define ldouble long double
const lint defMax = INT_MAX;
const int maxStrLen = 1000;

// Mersenne Twister
mt19937_64 mersenne {static_cast<mt19937_64::result_type>(time(NULL))};

// Random integer generator
// Argument (range of generation)
lint randInt(lint l, lint r) {return uniform_int_distribution<lint>(l, r)(mersenne);}

// Random double generator
// Argument (range of generation)
ldouble randDouble(ldouble l, ldouble r) {return uniform_real_distribution<ldouble>(l, r)(mersenne);}

// Random Character generator
/* Arguments(type for capital(1) : small(0) : any (-1), 
list (empty by default) if character are to be chosen differently from alphabets)*/
char randChar(int type = -1, vector<char> lst = {}) {if (!lst.empty()) return lst[randInt(0, lst.size() - 1)];int val = randInt(0, 25);char a[] = {'a', 'A'};type = (type == -1 ? randInt(0, 1) : type);return (char)(val + a[type]);}

// Random string generator
/* Arguments (length of string, type for capital(1) : small(0) : any (-1), 
list (empty by default) if character are to be chosen differently from alphabets)*/
string generateString(int len, int type = -1, vector<char> lst = {}) {
	string res("");
	int sz = lst.size();
	for (int i = 0; i < len; i++) res += randChar(type, lst);
	return res;
}

// Random array generator (integer)
/* Arguments (number of elements in array, range of generation)*/
void generateArray(int col, int lbound = 0, int rbound = defMax) {
	for (int j = 0; j < col; j++) 
		cout << randInt(lbound, rbound) << " ";
	cout << "\n";
}

// Random array generator (long long integer)
/* Arguments (number of elements in array, range of generation)*/
void generateArray(int col, lint lbound = 0, lint rbound = defMax) {
	for (int j = 0; j < col; j++) 
		cout << randInt(lbound, rbound) << " ";
	cout << "\n";
}

// Random array generator (double)
/* Arguments (number of elements in array, range of generation)*/
void generateArray(int col, double lbound = 0, double rbound = defMax) {
	for (int j = 0; j < col; j++) 
		cout << randDouble(lbound, rbound) << " ";
	cout << "\n";
}

// Random array generator (long double)
/* Arguments (number of elements in array, range of generation)*/
void generateArray(int col, ldouble lbound = 0, ldouble rbound = defMax) {
	for (int j = 0; j < col; j++) 
		cout << randDouble(lbound, rbound) << " ";
	cout << "\n";
}

// Random array generator (string)
/* Arguments (number of element in array, boolean value for length of all strings to be same or not, 
maximum string length possible, type for capital(1) : small(0) : any (-1), 
list (empty by default) if character are to be chosen differently from alphabets)*/
void generateStringArray(int col, bool staticLength = false,  int mxLen = maxStrLen, int type = -1, vector<char> lst = {}) {
	for (int j = 0; j < col; j++) 
		cout << generateString((staticLength? mxLen : randInt(1, mxLen)), type, lst) << " ";
	cout << "\n";
}