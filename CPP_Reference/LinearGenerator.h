/*
*********************************
*      Level 2 Generators       *
*********************************
*/

// Random array generator
/* Parameters (number of elements in array, range of generation)*/
/* Return type : An Array*/
using namespace std;

// Integer
auto generateArray(int sz, int lbound = 0, int rbound = defMax) {
	vector<int> a(sz);
	for (int i = 0; i < sz; i++) 
		a[i] = randInt(lbound, rbound);
	return a;
}
// Double
auto generateArray(int sz, double lbound = 0, double rbound = defMax) {
	vector<double> a(sz);
	for (int i = 0; i < sz; i++) 
		a[i] = randDouble(lbound, rbound);
	return a;
}

// String
/* Additional Parameters (list (empty by default) if character are to be chosen differently from alphabets, minimum string length possible, maximum string length possible, 
type for capital(1) : small(0) : any (-1))*/
auto generateArray(int sz, vector<char> lst = {}, int minLen = 1,  int maxLen = maxStrLen, int type = -1) {
	vector<string> a(sz);
	for (int i = 0; i < sz; i++) 
		a[i] = generateString(randInt(minLen, maxLen), type, lst);
	return a;
}

// Permutation Generator
/* Parameters (Size of permutation) */
auto generatePermutation(int n) {
	vector<int> a(n);
	iota(begin(a), end(a), 1);
	shuffle(begin(a), end(a), default_random_engine(time(NULL)));
	return a;
}


/*
*********************************
*      Level 3 Generators       *
*********************************
*/

// Integer
auto generateMultiDimensionalArray(int dimCnt, vector<int> &dimensions, int lbound = 0, int rbound = defMax) {
	if (dimCnt == 0) {
		Matrix<int> *t = new Matrix<int>(0, randInt(lbound, rbound));
		return t;
	}

	Matrix<int> *t = new Matrix<int>(dimensions[dimCnt - 1], -1);

	for (int i = 0; i < dimensions[dimCnt - 1]; i++) 
		t->nxt[i] = generateMultiDimensionalArray(dimCnt - 1, dimensions, lbound, rbound);
	return t;
}
// Double
auto generateMultiDimensionalArray(int dimCnt, vector<int> &dimensions, double lbound = 0, double rbound = defMax) {
	if (dimCnt == 0) {
		Matrix<double> *t = new Matrix<double>(0, randDouble(lbound, rbound));
		return t;
	}

	Matrix<double> *t = new Matrix<double>(dimensions[dimCnt - 1], -1);

	for (int i = 0; i < dimensions[dimCnt - 1]; i++) 
		t->nxt[i] = generateMultiDimensionalArray(dimCnt - 1, dimensions, lbound, rbound);
	return t;
}
// String
/* Additional Parameters (list (empty by default) if character are to be chosen differently from alphabets, minimum string length possible, maximum string length possible, type for capital(1) : 
small(0) : any (-1))*/
auto generateMultiDimensionalArray(int dimCnt, vector<int> &dimensions, vector<char> lst = {}, int minLen = 1,  int maxLen = maxStrLen, int type = -1) {
	if (dimCnt == 0) {
		Matrix<string> *t = new Matrix<string>(0, generateString(randInt(minLen, maxLen), type, lst));
		return t;
	}
	Matrix<string> *t = new Matrix<string>(dimensions[dimCnt - 1], "");
	for (int i = 0; i < dimensions[dimCnt - 1]; i++) 
		t->nxt[i] = generateMultiDimensionalArray(dimCnt - 1, dimensions, lst, minLen, maxLen, type);
	return t;
}