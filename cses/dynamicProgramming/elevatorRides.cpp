#include<bits/stdc++.h>
using namespace std;

int n;
int *a;
int minn;
vector<int> m;

void recursion(int i, int w, vector<int> p ) {
	if (w < minn) {
		minn = w;
		m = p;
	}
	if (i == n) {
		return;
	}
	recursion(i + 1, w, p);

	if (a[i] != INT_MAX && w - a[i] >= 0) {
		p.push_back(i);
		recursion(i + 1, w - a[i], p );
	}

}

int main() {
	cin >> n;
	int x;
	cin >> x;
	a = new int[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	int j = 0;
	int *b = new int [n]; sort(a, a + n);
	for (int i = 0; i < n; i++)b[i] = a[i];
	vector<vector<int> > ans;

	while (j < n) {
		if (a[j] != INT_MAX) {
			minn = x;
			m.clear();
			recursion(j + 1, x - a[j], m);
			m.push_back(j);
			ans.push_back(m);
			for (auto k : m)a[k] = INT_MAX;
		}
		j++;
	}
	int i = 1;
	for (auto c : ans) {
		cout << i << "-> ";
		for (auto xx : c) {
			cout << b[xx] << " ";
		}
		cout << endl;
		i++;
	}
	cout << ans.size() << endl;
}