using namespace std;

#define int long long
#define double long double
const int defMax = INT_MAX;
const int maxStrLen = 1000;

// Mersenne Twister
mt19937_64 mersenne {static_cast<mt19937_64::result_type>(time(NULL))};


/*
*********************************
*      Level 1 Generators       *
*********************************
*/

// Random integer generator
// Argument (range of generation)
// Return type : int
int randInt(int l, int r) {return uniform_int_distribution<int>(l, r)(mersenne);}

// Random double generator
// Argument (range of generation)
// Return type : double
double randDouble(double l, double r) {return uniform_real_distribution<double>(l, r)(mersenne);}

// Random Character generator
/* Parameters(type for capital(1) : small(0) : any (-1), 
list (empty by default) if character are to be chosen differently from alphabets)*/
// Return type : char
char randChar(int type = -1, vector<char> lst = {}) {
	if (!lst.empty()) return lst[randInt(0, lst.size() - 1)];
	int val = randInt(0, 25);
	char a[] = {'a', 'A'};
	type = (type == -1 ? randInt(0, 1) : type);
	return (char)(val + a[type]);
}

// Random string generator
/* Parameters (length of string, type for capital(1) : small(0) : any (-1), 
list (empty by default) if character are to be chosen differently from alphabets)*/
// Return type String
string generateString(int len, int type = -1, vector<char> lst = {}) {
	string res("");
	int sz = lst.size();
	for (int i = 0; i < len; i++) res += randChar(type, lst);
	return res;
}





