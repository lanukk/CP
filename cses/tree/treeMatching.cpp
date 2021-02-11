#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>parent;
vector<vector<int>>adj;
vector<int>d;
vector<bool>visited;
queue<int> q;

#define INF 1e9

int dp[200005][3];


int bfs(int v) {

	d.assign(n + 1, INF);
	visited.assign(n + 1, 0);

	d[v] = 0;
	visited[v] = 1;
	q.push(v);

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int x : adj[f]) {
			if (!visited[x]) {
				visited[x] = 1;
				d[x] = min(d[x], d[f] + 1);
				q.push(x);
			}
		}
	}

	int maxx = 0 ;
	int node;
	for (int i = 1; i <= n; i++) {
		if (d[i] > maxx) {
			maxx = d[i];
			node = i;
		}
	}

	return node;
}


int recursion(int v, int f) {
	int k = 0;
	if (dp[v][f] != -1)
		return dp[v][f];

	for (int x : adj[v]) {
		if (x == parent[v])
			continue;
		parent[x] = v;

		if (f == 1) {
			k = max(k, recursion(x, 0));
		}
		else {
			k = max(k, recursion(x, 1) + 1);
			k = max(k, recursion(x, 0));
		}
	}

	return dp[v][f] = k;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	if (n == 1) {
		cout << "0";
		return 0;
	}
	parent.assign(n + 1, -1);
	adj.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int node = bfs(1);
	int ans = 0;

	for (int x : adj[node]) {
		ans = max(ans, recursion(x, 1) + 1);
		ans = max(ans, recursion(x, 0));
	}

	cout << ans;
}