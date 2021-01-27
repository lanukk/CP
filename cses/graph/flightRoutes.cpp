#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define INF 100000000000000000LL

int n, m;
vector<vector<pair<int, int> >>adj;
vector<int>d;
priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int> > > q;
multiset<int> s;

signed main() {
	cin >> n >> m;
	adj.resize(n + 1);
	d.assign(n + 1, INF);
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
	}
	q.push({0, 1});
	while (!q.empty()) {
		pair<int, int> f = q.top();
		q.pop();
		if (f.first > d[f.second])continue;
		for (auto x : adj[f.second]) {
			if (d[x.first] == f.first + x.second  && x.first == n) {
				s.insert(x.first);
			}
			if (d[x.first] > f.first + x.second) {
				d[x.first] = f.first + x.second;
				if (x.first == n) {
					s.insert(d[x.first]);
				}
				q.push({d[x.first], x.first});
			}
		}
	}

}