#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define INF 1e17
int n, m;
vector<vector<pair<int, int>>>adj;
priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>>q;


signed main() {
	cin >> n >> m;
	int d[n + 1][2];
	for (int i = 2; i <= n; i++) {
		d[i][0] = INF;
		d[i][1] = INF;
	}
	adj.resize(n + 1);
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
	}
	d[1][0] = 0;
	d[1][1] = 0;
	q.push({0, {1, 0}});
	while (!q.empty()) {
		pair<int, pair<int, int> > a = q.top();
		q.pop();
		int u = a.second.first;
		int coupon = a.second.second;
		int travelled = a.first;
		if (coupon == 0) {
			if (travelled > d[u][0])continue;
		}
		else {
			if (travelled > d[u][1])continue;
		}
		for (auto x : adj[u]) {
			int v = x.first;
			int cost = x.second;
			if (coupon == 0) {
				if (d[v][1] > travelled + cost / 2) {
					d[v][1] = travelled + cost / 2;
					q.push({d[v][1], {v, 1}});
				}
				if (d[v][0] > travelled + cost) {
					d[v][0] = travelled + cost;
					q.push({d[v][0], {v, 0}});
				}
			}
			else {
				if (d[v][1] > travelled + cost) {
					d[v][1] = travelled + cost;
					q.push({d[v][1], {v, 1}});
				}
			}
		}
	}
	cout << min(d[n][0], d[n][1]);
}