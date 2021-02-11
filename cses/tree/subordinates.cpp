#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>adj;
vector<pair<int, int> >timer;

int d = 1 ;

void dfs(int v) {
	timer[v].first = d;

	for (int  x : adj[v]) {
		d++;
		dfs(x);
	}
	timer[v].second = d;
}



int main() {
	cin >> n ;
	adj.resize(n + 1);
	for (int i = 2 ; i <= n ; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
	}
	timer.resize(n + 1, {0, 0});
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << -timer[i].first + timer[i].second << " ";
	}
}