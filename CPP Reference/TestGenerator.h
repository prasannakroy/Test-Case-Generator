#include<bits/stdc++.h>
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


/*
*********************************
*      Level 2 Generators       *
*********************************
*/

// Random array generator
/* Parameters (number of elements in array, range of generation)*/
/* Return type : An Array*/

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


/*
*********************************
*      Level 3 Generators       *
*********************************
*/

// Multi Dimensional Array Generator
/* Parameters (number of dimensions of array, a list of size of all dimensions(passed by reference, range of generation) */

// Integer
void generateMultiDimensionalArray(int dimCnt, vector<int> &dimensions, int lbound = 0, int rbound = defMax) {
	if (dimCnt == 0) return void(cout << randInt(lbound, rbound) << " ");
	for (int i = 0; i < dimensions[dimCnt - 1]; i++) 
		generateMultiDimensionalArray(dimCnt - 1, dimensions, lbound, rbound);
	cout << "\n";
}
// Double
void generateMultiDimensionalArray(int dimCnt, vector<int> &dimensions, double lbound = 0, double rbound = defMax) {
	if (dimCnt == 0) return void(cout << randDouble(lbound, rbound) << " ");
	for (int i = 0; i < dimensions[dimCnt - 1]; i++) 
		generateMultiDimensionalArray(dimCnt - 1, dimensions, lbound, rbound);
	cout << "\n";
}
// String
/* Additional Parameters (list (empty by default) if character are to be chosen differently from alphabets, minimum string length possible, maximum string length possible, type for capital(1) : 
small(0) : any (-1))*/
void generateMultiDimensionalArray(int dimCnt, vector<int> &dimensions, vector<char> lst = {}, int minLen = 1,  int maxLen = maxStrLen, int type = -1) {
	if (dimCnt == 0) return void(cout << generateString(randInt(minLen, maxLen), type, lst) << "\n");
	for (int i = 0; i < dimensions[dimCnt - 1]; i++) 
		generateMultiDimensionalArray(dimCnt - 1, dimensions, lst, minLen, maxLen, type);
	cout << "\n";
}


/*
*********************************
*     Non-Linear Generators     *
*********************************
*/

// Structure to store tree properties
struct Tree {
	int sz;
	vector<array<int, 3>> edges;
	vector<vector<array<int, 2>>> adj;
	vector<int> parent, prufer;

	Tree(int sz) : sz(sz) {
		parent.resize(sz + 1);
		prufer.resize(sz - 2);
		adj.resize(sz + 1);
	}

	void addEdge(int u, int v, int wt) {
		edges.push_back({u, v, wt});
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
};

// Tree DFS traversal to generate parent array
void dfs(Tree &tr, int u, int p) {
	tr.parent[u] = p;
	for (auto &v: tr.adj[u]) if (v[0] != p) dfs(tr, v[0], u);
}

// Standard Tree Generator
/* Parameters (number of nodes in tree, flag for edge weight, range of edge weight, 
indexing type (0 based or 1 based, 1 by default), root of tree if rooted) */
auto generateTree(int n, bool weighted = false, int lbound = 1, int rbound = defMax, int indexing = 1, int root = 1) {
	int rt = 1;
	if (!indexing) rt--;

	Tree tr(n);
	vector<int> degree(n + rt, 1);
	tr.prufer = generateArray(n - 2, rt, rt + n - 1);
	for (auto &i: tr.prufer) degree[i]++;

	int cur(rt), minLeaf;
	while(degree[cur] != 1) cur++;
	minLeaf = cur;
	for (auto &i: tr.prufer) {
		tr.addEdge(minLeaf, i, (weighted ? randInt(lbound, rbound) : 0));
		degree[i]--;
		if (degree[i] == 1 and i < cur) minLeaf = i;
		else {
			while (degree[++cur] != 1);
			minLeaf = cur;
		}
	}
	tr.addEdge(minLeaf, rt + n - 1, (weighted ? randInt(lbound, rbound) : 0));
	dfs(tr, root, -1);
	return tr;
}