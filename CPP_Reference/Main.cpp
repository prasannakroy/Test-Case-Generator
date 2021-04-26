#include <bits/stdc++.h>
#include "Primitive.h"
#include "Matrix.h"
#include "LinearGenerator.h"
using namespace std;
#define int long long
#define double long double

#define szMax 1000000

void solve() {
  string ds;
  cin >> ds;
  if (ds == "numArray") {
    int dm;
    cin >> dm;
    assert(dm >= 1 and dm <= 1000);
    vector<int> sz(dm);
    for (auto &i: sz) cin >> i;
    int lBound, rBound;
    cin >> lBound >> rBound;
    assert(lBound <= rBound);
    auto res = *generateMultiDimensionalArray(dm, sz, lBound, rBound);
    res.printArray();
  }
  else {
    cout << "Invalid DS\n";
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