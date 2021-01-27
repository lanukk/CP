#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>adj;
vector<int>color;
vector<int>ans;
vector<int>parent;

void dfs(int v) {
	color[v] = 1;
	for (int x : adj[v]) {
		if (color[x] == 1 && (int)ans.size() == 0) {
			//cycle found
			int cycle_start = x;
			int cycle_end = v;
			ans.push_back(x);
			for (int v =  cycle_end ; v != cycle_start; v = parent[v])
				ans.push_back(v);
			ans.push_back(x);
		}
		if (color[x] == 0) {
			parent[x] = v;
			dfs(x);
		}
	}
	color[v] = 2;
}


int main() {
	cin >> n >> m;
	parent.assign(n + 1, -1);
	adj.resize(n + 1);
	color.assign(n + 1, 0);
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1 ; i <= n; i++) {
		if (color[i] == 0) {
			dfs(i);
		}
	}
	if ((int)ans.size() == 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << ans.size() << endl;
	for (int i = (int)ans.size() - 1; i >= 0 ; i--) {
		cout << ans[i] << " ";
	}
}