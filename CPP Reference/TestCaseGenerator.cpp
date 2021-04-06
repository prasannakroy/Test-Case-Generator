#include <bits/stdc++.h>
#include "Primitive.h"
#include "Tree.h"
#include "Matrix.h"
#include "LinearGenerator.h"
#include "NonLinearGenerator.h"
using namespace std;
#define int long long
#define double long double

void solve() {
	vector<char> lst = {'.', '+', '*', '/', '-', '='};
	vector<int> dm = {3, 3};
	auto res = *generateMultiDimensionalArray(2, dm, lst, 5, 7, 1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cout << res[i][j].data << " ";
		cout << "\n";
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    while (t--) solve();
}