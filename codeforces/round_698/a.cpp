#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		map<int, int> mp;
		for (int i = 0 ; i < n; i++) {
			cin >> a[i]; mp[a[i]]++;
		}
		int maxx = 0;
		for (auto x : mp)maxx = max(maxx, x.second);
		cout << maxx << endl;
	}
}