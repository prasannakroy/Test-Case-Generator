class Tree {
private:
	int sz, root, index, lbound, rbound;
	bool weighted;
	vector<array<int, 3>> edges;
	vector<vector<array<int, 2>>> adj;
	vector<int> parent, prufer;

public:

	Tree(int sz = 0, bool weighted = false, int lbound = 0, int rbound = defMax, int index = 1, int root = 1, vector<int> prufer = {}) : 
	sz(sz), prufer(prufer), root(root), index(index), weighted(weighted), lbound(lbound), rbound(rbound) {
		parent.resize(sz + index);
		adj.resize(sz + index);
		build("PruferCode");
	}

	Tree(vector<vector<array<int, 2>>> adj, int sz = 0, bool weighted = false, int lbound = 0, int rbound = defMax, int index = 1, int root = 1) : 
	sz(sz), adj(adj), root(root), index(index), weighted(weighted), lbound(lbound), rbound(rbound) {
		parent.resize(sz + index);
		if (sz - 2) prufer.resize(sz - 2);
		build("AdjacencyList");
	}

	Tree(vector<array<int, 3>> edges, int sz = 0, bool weighted = false, int lbound = 0, int rbound = defMax, int index = 1, int root = 1) : 
	sz(sz), edges(edges), root(root), index(index), weighted(weighted), lbound(lbound), rbound(rbound) {
		parent.resize(sz + index);
		if (sz - 2) prufer.resize(sz - 2);
		adj.resize(sz + index);
		build("EdgeList");
	}

	Tree(vector<int> parent = {}, int sz = 0, bool weighted = false, int lbound = 0, int rbound = defMax, int index = 1, int root = 1) : 
	sz(sz), parent(parent), root(root), index(index), weighted(weighted), lbound(lbound), rbound(rbound) {
		if (sz - 2) prufer.resize(sz - 2);
		adj.resize(sz + index);
		build("ParentArray");
	}

	void build(string);
	void buildFromPrufer();
	void buildFromAdjacencyList();
	void buildFromEdgeList();
	void buildFromParentArray();
	void addEdge(int, int, int);
	void dfs(int, int);
	void buildPrufer();

	int getSize();
	vector<array<int, 3>> getEdgeList();
	vector<int> getPruferCode();
	vector<int> getParentArray();
	vector<vector<array<int, 2>>> getAdjacencyList();

};

void Tree :: addEdge(int u, int v, int wt) {
	edges.push_back({u, v, wt});
	adj[u].push_back({v, wt});
	adj[v].push_back({u, wt});
}

void Tree :: dfs(int u, int p) {
	parent[u] = p;
	for (auto &v: adj[u]) if (v[0] != p) 
		dfs(v[0], u);
}

void Tree :: buildPrufer() {
	dfs(sz + index - 1, -1);
	int ptr = -1;
	vector<int> degree(sz + index);
	for (int i = index; i < sz + index; i++) {
		degree[i] = adj[i].size();
		if (degree[i] == 1 and ptr == -1) ptr = i;
	}

	int minLeaf = ptr;
	for (int i = 0; i < sz - 2; i++) {
		int nxt = parent[minLeaf];
		prufer[i] = nxt;
		if (--degree[i] == 1 and nxt < ptr) minLeaf = nxt;
		else {
			while(degree[++ptr] != 1) ptr++;
			minLeaf = ptr;
		}
	}
}

void Tree :: buildFromPrufer() {
	vector<int> degree(sz + index, 1);
	for (auto &i: prufer) 
		degree[i]++;

	int cur(index);
	while(degree[cur] != 1) cur++;
	int minLeaf = cur;

	for (auto &i: prufer) {
		addEdge(minLeaf, i, (weighted ? randInt(lbound, rbound) : 0));
		degree[i]--;
		if (degree[i] == 1 and i < cur) minLeaf = i;
		else {
			while (cur < sz + index and degree[++cur] != 1);
			minLeaf = cur;
		}
	}
	addEdge(minLeaf, index + sz - 1, (weighted ? randInt(lbound, rbound) : 0));

	dfs(root, -1);
}

void Tree :: buildFromAdjacencyList() {
	for (int u = index; u < sz + index; u++) 
		for (auto &v : adj[u]) 
			edges.push_back({u, v[0], v[1]});

	buildPrufer();
	dfs(root, -1);
}

void Tree :: buildFromEdgeList() {
	for (auto &edge : edges) {
		adj[edge[0]].push_back({edge[1], edge[2]});
		adj[edge[1]].push_back({edge[0], edge[2]});
	}

	buildPrufer();
	dfs(root, -1);
}

void Tree :: buildFromParentArray() {
	for (int i = index; i < sz + index; i++) {
		if (parent[i] != -1) 
			addEdge(i, parent[i], (weighted ? randInt(lbound, rbound) : 0));
		else root = i;
	}

	buildPrufer();
	dfs(root, -1);
}

void Tree :: build(string s) {
	if (s == "PruferCode") 
		buildFromPrufer();

	else if (s == "AdjacencyList") 
		buildFromAdjacencyList();

	else if (s == "EdgeList") 
		buildFromEdgeList();

	else 
		buildFromParentArray();
}

int Tree :: getSize() { return sz; }

vector<array<int, 3>> Tree :: getEdgeList() { return edges; }

vector<int> Tree :: getPruferCode() { return prufer; }

vector<int> Tree :: getParentArray() { return parent; }

vector<vector<array<int, 2>>> Tree :: getAdjacencyList() { return adj; }
