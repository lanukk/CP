#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int>parent;
set<pair<int, int> > s;
//priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q;
vector<vector<int >>adj;
vector<int>d;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m;
	adj.resize(n + 1);
	d.assign(n + 1, 0);
	parent.assign(n + 1, -1);
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y;
		adj[x].push_back(y);
	}


	d[1] = 0;
	s.insert({0, 1});
	//q.push({0, 1});
	// while (!q.empty()) {
	// 	pair<int, int> f = q.top();
	// 	q.pop();
	// 	if (d[f.second] < f.first)continue;
	// 	for (int x : adj[f.second]) {
	// 		if (d[x] > f.first - 1) {
	// 			d[x] = f.first - 1;
	// 			parent[x] = f.second;
	// 			q.push({d[x], x});
	// 		}
	// 	}
	// }
	while (!s.empty()) {
		pair<int, int> f = *s.begin();
		s.erase(s.begin());
		for (int x : adj[f.second]) {
			if (d[x] > f.first - 1) {
				s.erase({d[x], x});
				parent[x] = f.second;
				d[x] = f.first - 1;
				s.insert({d[x], x});
			}
		}
	}

	if (d[n] == 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> ans;
	for (int v = n; v != 1; v = parent[v]) {
		ans.push_back(v);
	}
	ans.push_back(1);
	cout << (int)ans.size() << "\n";
	for (int i = (int)ans.size() - 1 ; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}