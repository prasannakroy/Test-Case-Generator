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
	auto lst = generateDirectedGraphList(10, 15, 1, 10, 250);
	for (auto &i: lst) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    while (t--) solve();
}