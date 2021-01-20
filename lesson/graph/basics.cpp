#include<bits/stdc++.h>
using namespace std;


int main() {

	vector<vector<int>>adj;

	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}