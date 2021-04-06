auto generateTree(int n, bool weighted = false, int lbound = 1, int rbound = defMax, int index = 1, int root = 1) {
	vector<int> randPrufer = generateArray(n - 2, index, index + n - 1);

	Tree tr(n, weighted, lbound, rbound, index, root, randPrufer);
	return tr;
}