#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>adj;
vector<int>ans;
vector<int>d;
vector<bool>visited;
queue<int> q;
vector<int>parent;

#define INF 1e9

void bfs(int v) {
	parent.assign(n + 1, -1);
	d.assign(n + 1, INF);
	visited.assign(n + 1, 0);
	d[v] = 0 ;
	visited[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int x : adj[f]) {
			if (!visited[x]) {
				parent[x] = f;
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
	vector<int>nodes;
	int max_distance = 0 ;
	int node ;

	for (int i = 1; i <= n; i++) {
		if (d[i] > max_distance) {
			nodes.clear();
			max_distance = d[i];
			node = i;
		}
		if (d[i] == max_distance) {
			nodes.push_back(i);
		}
	}

	ans.resize(n + 1);
	bfs(node);
	int start;
	max_distance = 0 ;
	for (int i = 1; i <= n; i++) {
		if (d[i] > max_distance) {
			max_distance = d[i];
			start = i;
		}
	}
	int till = 0 ;
	vector<int>path;

	visited.assign(n + 1, 0);
	for (int  v = start; v != node; v = parent[v]) {
		path.push_back(v);
		visited[v] = 1;
		q.push(v);
	}
	visited[node] = 1;
	path.push_back(node);
	q.push(node);
	for (int x : path) {
		d[x] = max(d[x], till);
		till++;
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int x : adj[f]) {
			if (!visited[x]) {
				d[x] = max(d[x], d[f] + 1);
				q.push(x);
				visited[x] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}