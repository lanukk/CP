#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n;

signed main() {
	cin >> n;

	int x;
	cin >> x;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	while (i < j) {
		if (v[i].first + v[j].first > x) {
			j--;
		}
		else if (v[i].first + v[j].first < x) {
			i++;
		}
		else {
			cout << v[i].second + 1 << " " << v[j].second + 1;
			return 0;
			break;
		}
	}
	cout << "IMPOSSIBLE";

}