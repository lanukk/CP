#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>adj;
vector<bool>visited;
vector<int>parent;

void dfs(int v) {
	visited[v] = 1;
	for (int x : adj[v]) {

		if (visited[x] == true && x != parent[v]) {
			vector<int> ans;

			int i = v;
			while (parent[i] != x) {
				ans.push_back(i);
				i = parent[i];
			}
			ans.push_back(i);
			ans.push_back(x);
			ans.push_back(v);
			cout << ans.size() << endl;
			for (int x : ans) {
				cout << x << " ";
			}
			exit(0);
		}
		if (!visited[x]) {
			parent[x] = v;
			dfs(x);
		}
	}
}


int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visited.assign(n + 1, 0);
	parent.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			parent[i] = -1;
			dfs(i);
		}
	}
	cout << "IMPOSSIBLE";
}