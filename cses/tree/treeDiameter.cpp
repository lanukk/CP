#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>adj;
vector<int>d;
vector<bool>visited;
#define INF 1e9

queue<int> q;

void bfs(int v) {
	q.push(v);
	d.assign(n + 1, INF);
	visited.assign(n + 1, 0);
	d[v] = 0;
	visited[v] = 1;

	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int x : adj[f]) {
			if (!visited[x]) {
				d[x] = min(d[x], d[f] + 1);
				visited[x] = 1;
				q.push(x);
			}
		}
	}
}

int main() {
	cin >> n;
	if (n == 1) {
		cout << "0";
		return 0;
	}
	adj.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(1);
	int maxx_distance = 0 ;
	int node;
	for (int i = 1; i <= n; i++) {
		if (d[i] > maxx_distance) {
			maxx_distance = d[i];
			node = i;
		}
	}
	bfs(node);
	maxx_distance = 0 ;
	for (int i = 1; i <= n; i++) {
		maxx_distance = max(maxx_distance, d[i]);
	}
	cout << maxx_distance;

}