#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int>color;
vector<int>ans;
vector<vector<int>>adj;
bool possible = 1;

void dfs(int v) {
	color[v] = 1;
	for (int x : adj[v]) {
		if (color[x] == 1) {
			possible = 0 ;
		}
		if (!color[x])
			dfs(x);
	}
	color[v] = 2;
	ans.push_back(v);
}

int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	color.assign(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dfs(i);
		}
	}
	if (!possible) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = (int)ans.size() - 1 ; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}