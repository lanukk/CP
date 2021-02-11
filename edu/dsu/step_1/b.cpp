#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int>parent;

struct node {
	int size = 0 ;
	int maxx = INT_MIN;
	int minn = INT_MAX;
};
vector<node> v;

int get_parent(int v) {
	if (parent[v] == v)
		return v;
	return parent[v] = get_parent(parent[v]);
}

void unite(int a, int b) {
	int x = get_parent(a);
	int y = get_parent(b);

	if (x != y) {
		if (v[y].size > v[x].size)
			swap(x, y);
		v[x].minn = min(v[x].minn, v[y].minn);
		v[x].maxx = max(v[x].maxx, v[y].maxx);
		v[x].size += v[y].size;
		parent[y] = x;

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	v.resize(n + 1);
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		v[i].size = 1;
		v[i].minn = i;
		v[i].maxx = i;
	}
	while (q--) {
		string s;
		int a, b;
		cin >> s;
		if (s == "union") {
			cin >> a >> b;
			unite(a, b);
		}
		else {
			cin >> a;
			int z = get_parent(a);
			cout <<  v[z].minn << " " << v[z].maxx << " " << v[z].size << endl;
		}
	}
}