#include<bits/stdc++.h>
#include "TestGenerator.h"
using namespace std;
#define int long long
#define double long double

void solve() {
	// double x = 10.51;
	// double y = 25.54;
	// cout << randInt(-14, 5) << "\n";
	// auto a = generateArray(5, x, y); // generates a 5 * 5 array with random element in range 10 - 25.
	// for (auto &i: a) cout << i << " ";
	// auto a = generateArray(5, 0, 5, 0, {'/', '*', '+'}); // generate an array of string of length 5 with each element being a string of length 5.
	// for (auto &i: a) cout << i << "\n";
	// cout << "\n";
	// int dim = 5;
	// vector<int> a = {2, 2, 3, 2, 2};
	// vector<char> lst;
	// double x = 20.0, y = 100.0;
	// generateMultiDimensionalArray(dim, a, x, y);
	// generateMultiDimensionalArray(dim, a, lst, 1, 10, -1);
	int n = 5;
	auto tr = generateTree(5, false, 1, 20, 1, 5);
	for (int i = 1; i <= n; i++) cout << tr.parent[i] << " ";
	cout << "\n";
	for (auto &edge : tr.edges) 
		cout << edge[0] << " " << edge[1] << " " << edge[2] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    while (t--) solve();
}