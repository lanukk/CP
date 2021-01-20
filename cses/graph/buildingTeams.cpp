#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>adj;
vector<bool> visited;
vector<int>color;

void dfs(int v, bool c) {
	visited[v] = 1;
	if (c)color[v] = 2;
	else color[v] = 1;

	for (int x : adj[v]) {
		if (color[x] == color[v]) {
			cout << "IMPOSSIBLE" << endl;
			exit(0);
		}
		if (!visited[x]) {
			dfs(x, !c);
		}
	}
}

int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	color.assign(n + 1, 0);
	visited.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i, 0);
	}
	for (int i = 1; i <= n; i++) {
		cout << color[i] << " ";
	}
}