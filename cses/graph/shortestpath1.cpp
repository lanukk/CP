#include<bits/stdc++.h>
using namespace std;

int n;
int m;
vector<vector<pair<int, int> > > adj;
#define int long long int
set<pair<int, int> > s;
vector<int> dist;
#define INF 1e17

signed main() {
	cin >> n >> m;
	adj.resize(n + 1);
	dist.assign(n + 1, INF);
	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
	}
	dist[1] = 0 ;
	s.insert({0, 1});
	while (!s.empty()) {
		pair<int, int> f = *s.begin();
		s.erase(s.begin());
		for (auto x : adj[f.second]) {
			if (dist[x.first] > dist[f.second] + x.second) {
				s.erase({dist[x.first], x.first});
				dist[x.first] = dist[f.second] + x.second;
				s.insert({dist[x.first], x.first});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
}