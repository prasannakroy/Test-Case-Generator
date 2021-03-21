#include<bits/stdc++.h>
#include "TestGenerator.h"
using namespace std;
#define int long long

void solve() {
	cout << randInt(-14, 5) << "\n";
	generateArray(5, 10, 25); // generates a 5 * 5 array with random element in range 10 - 25.
	generateStringArray(5, 0, 5, 0, {'/', '*', '+'}); // generate an array of string of length 5 with each element being a string of length 5.
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    while (t--) solve();
}