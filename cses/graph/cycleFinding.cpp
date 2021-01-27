#include<bits/stdc++.h>
using namespace std;
#define NINF -100000000000000000LL
#define int long long int
int n, m;
vector<vector<pair<int, int> >>adj;
struct node {
	int a, b, w;
};
node *e;
vector<int>d;
vector<int>parent;
int cycle_start; vector<int> ans;



signed main() {
	cin >> n >> m;
	parent.assign(n + 1, -1);
	adj.resize(n + 1);
	e = new node [m];
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
		e[i].a = x;
		e[i].b = y;
		e[i].w = wt;
	}
	d.assign(n + 1, 0);

	for (int i = 0 ; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (d[e[j].b] > d[e[j].a] + e[j].w) {
				d[e[j].b] = d[e[j].a] + e[j].w;
				parent[e[j].b] = e[j].a;
				d[e[j].b] = max(d[e[j].b], NINF);
			}
		}
	}
	int cycle_potential = - 1;
	for (int j = 0; j < m; j++) {
		if (d[e[j].b] > d[e[j].a] + e[j].w) {
			d[e[j].b] = NINF;
			cycle_potential = e[j].b;
		}
	}
	if (cycle_potential  == -1) {
		cout << "NO";
		return 0;
	}
	map<int, bool> mp;

	cycle_start = cycle_potential;
	while (1) {
		if (mp[cycle_start] == 1) {
			ans.push_back(cycle_start);
			break;
		}
		else {
			mp[cycle_start] = 1;
			ans.push_back(cycle_start);
			cycle_start = parent[cycle_start];
		}
	}
	cout << "YES" << endl;
	if (cycle_potential == cycle_start) {
		reverse(ans.begin(), ans.end());
		for (int x : ans)cout << x << " ";

	}
	else {
		reverse(ans.begin(), ans.end());
		for (int i = 0 ; i < (int)ans.size() - 1; i++) {
			cout << ans[i] << " ";
		}
	}
}