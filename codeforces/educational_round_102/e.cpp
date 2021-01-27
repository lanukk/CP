#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int> > > adj;

struct node {
	int d, v, mx, mn;
};

struct dm {
	int d, mn, mx;
};
dm d[200010];
bool comp(node a, node b) {
	return a.d < b.d;
}
set<node, decltype(comp)*> s(comp);

#define INF 1e9
int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
		adj[y].push_back({x, wt});
	}

	for (int i = 1; i <= n; i++) {
		d[i].d = INF;
		d[i].mn = INT_MAX;
		d[i].mx = INT_MIN;
	}
	d[1].d = 0;
	node f;
	f.d = 0;
	f.v = 1;
	f.mx = 0;
	f.mn = 0;
	s.insert(f);
	while (!s.empty()) {

		f = *s.begin();
		s.erase(f);
		for (auto x : adj[f.v]) {
			int dist;
			if (x.second > f.mx || x.second < f.mn) {
				dist = d[f.v].d + f.mx - f.mn;

				if (x.second > f.mx) {
					dist = dist + f.mn ;
				}
				else {
					dist = dist - f.mx;
				}

			}
			else {
				dist = d[f.v].d + x.second;
			}
			if (d[x.first].d > dist) {
				node dummy;
				dummy.d = d[x.first].d;
				dummy.v = x.first;
				dummy.mn = d[x.first].mn;
				dummy.mx = d[x.first].mx;
				s.erase(dummy);
				d[x.first].d = dist;
				d[x.first].mn = min(x.second, f.mn);
				d[x.first].mx = max(x.second, f.mx);
				dummy.d = dist;
				dummy.mn = min(x.second, f.mn);
				dummy.mx = max(x.second, f.mx);
				s.insert(dummy);
			}
		}

	}
	for (int i = 2; i <= n; i++) {
		cout << d[i].d + 1 << " ";
	}
}