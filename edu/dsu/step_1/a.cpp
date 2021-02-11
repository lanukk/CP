#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int>parent;


int get_parent(int a) {
	if (parent[a] == a) {
		return a;
	}

	return parent[a] = get_parent(parent[a]);
}

void unite(int a, int b) {
	int parent_a = get_parent(a);
	int parent_b = get_parent(b);

	parent[parent_b] = parent_a;
}

int main() {
	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		string s;
		cin >> s;
		int a, b;
		cin >> a >> b;

		if (s == "union") {
			unite(a, b);
		}
		else {
			if (get_parent(a) == get_parent(b)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}