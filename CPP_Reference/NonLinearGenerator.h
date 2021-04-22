auto generateTree(int n, bool weighted = false, int lbound = 1, int rbound = defMax, int index = 1, int root = 1) {
	vector<int> randPrufer = generateArray(n - 2, index, index + n - 1);

	Tree tr(n, weighted, lbound, rbound, index, root, randPrufer);
	return tr;
}

auto generateUndirectedGraphList(int nodes, int edges, bool weighted = false, int lbound = 0, int rbound = defMax, int index = 1) {
	vector<vector<int>> lst;
	map<pair<int, int>, int> mp;
	int l = 1 + index - 1;
	int r = nodes + index - 1;
	for (int i = 0; i < edges; i++) {
		int x = randInt(l, r);
		int y = randInt(l, r);
		if (x == y) {
			i--;
			continue;
		} 
		if (x > y) swap(x, y);
		if (mp[{x, y}]) {
			i--;
			continue;
		}
		lst.push_back({x, y});
		mp[{x, y}] = 1;
		if (weighted) lst.back().push_back(randInt(lbound, rbound));
	}
	return lst;
}

auto generateDirectedGraphList(int nodes, int edges, bool weighted = false, int lbound = 0, int rbound = defMax, int index = 1) {
	vector<vector<int>> lst;
	map<pair<int, int>, int> mp;
	int l = 1 + index - 1;
	int r = nodes + index - 1;
	for (int i = 0; i < edges; i++) {
		int x = randInt(l, r);
		int y = randInt(l, r);
		if (x == y) {
			i--;
			continue;
		} 
		if (mp[{x, y}]) {
			i--;
			continue;
		}
		lst.push_back({x, y});
		mp[{x, y}] = 1;
		if (weighted) lst.back().push_back(randInt(lbound, rbound));
	}
	return lst;
}