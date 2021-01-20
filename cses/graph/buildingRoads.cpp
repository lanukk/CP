#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > adj;
int m;
vector<bool> visited;

void dfs(int v) {
	visited[v] = 1;
	for (auto x : adj[v]) {
		if (visited[x] == 0)
			dfs(x);
	}
}


int main() {
	cin >> n;
	adj.resize(n + 1);
	cin >> m;
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visited.assign(n + 1, 0);
	vector<int> ans;
	for (int i = 1 ; i <= n; i++) {
		if (visited[i] == 0) {
			ans.push_back(i);
			dfs(i);
		}
	}
	cout << ans.size() - 1 << endl;
	for (int i = 1; i < (int)ans.size(); i++) {
		cout << ans[i] << " " << ans[i - 1] << endl;
	}

}
