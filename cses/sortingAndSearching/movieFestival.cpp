#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > a;

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	});
	int ans = 0;
	for (int i = 0 ; i < n; i++) {
		ans++;
		int j = i + 1;
		while (j < n && a[j].first < a[i].second) {
			j++;
		}
		i = j - 1;
	}
	cout << ans;
}