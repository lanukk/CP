#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int> >> adj;
#define INF 1e9
vector<int>parent;
vector<int>d;
struct edge {
	int a, b, w;
};
vector<vector<int>> cycles;
vector<int> visited;


int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	edge e[m];
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		e[i].a = x;
		e[i].b = y;
		e[i].w = wt;
		adj[x].push_back({y, wt});
	}
	d.assign(n + 1, INF);

	d[1] = 0;
	parent.assign(n + 1, -1);
	for (int i = 0 ; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (d[e[j].a] < INF) {
				if (d[e[j].b] > d[e[j].a] + e[j].w) {
					d[e[j].b] = d[e[j].a] + e[j].w;
					parent[e[j].b] = e[j].a;
				}
			}
		}
	}
	vector<int>ans;
	int x = n;
	while (parent[x] != -1) {
		ans.push_back(x);
		x = parent[x];
	}

}