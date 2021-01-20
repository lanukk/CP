#include<bits/stdc++.h>

using namespace std;
// 8 7
// 2 3
// 1 2
// 1 4
// 5 1
// 1 6
// 5 7
// 2 8

vector<vector<int>>adj;


vector<bool>visited;
int n;
int m;


void dfs(int v) {
	visited[v] = 1;
	if (adj[v].size() == 1) {
		cout << v << endl;
		return;
	}

	for (auto x : adj[v]) {
		if (visited[x] == 0) {
			dfs(x);

		}
	}
}

int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	visited.assign(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
}