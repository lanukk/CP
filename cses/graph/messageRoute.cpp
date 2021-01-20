#include<bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>>adj;
int m;
vector<bool>visited;
vector<int> parent;

int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	parent.assign(n + 1, 0);
	visited.assign(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	parent[1] = -1 ;
	visited[1] = 1 ;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x : adj[v]) {

			if (visited[x] == 0) {
				parent[x] = v;
				q.push(x);
				visited[x] = 1;
				if (x == n)
					break;
			}
		}
	}
	if (!visited[n]) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> ans;
	int i = n;
	ans.push_back(n);
	while (parent[i] != -1) {
		ans.push_back(parent[i]);
		i = parent[i];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto  x : ans) {
		cout << x << " ";
	}

	return 0;
}