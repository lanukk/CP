#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define int long long int
int n, m;
vector<vector<int>>adj;
vector<int>d;

void dfs(int v) {
	for (int x : adj[v]) {
		d[x] = (d[x] + d[v]) % MOD;
		dfs(x);
	}
}

signed main() {
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	d.assign(n + 1, 0);
	d[1] = 1;
	dfs(1);
	cout << (d[n] % MOD);
}