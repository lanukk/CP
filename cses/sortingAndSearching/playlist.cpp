#include<bits/stdc++.h>
using namespace std;

int n;
int *a;

int main() {
	cin >> n;
	a = new int[n];
	map<int, int> mp;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1 ;
	int l = 0, r = 1;
	mp[a[l]]++;
	//cout << ans;
	map<int, int> index;
	index[a[l]] = l;
	while (r < n) {
		mp[a[r]]++;
		if (mp[a[r]] == 2) {
			int i = index[a[r]];
			while (l <= i) {
				mp[a[l]]--;
				l++;
			}
		}
		index[a[r]] = r ;
		ans = max(r - l + 1, ans);
		r++;
	}
	cout << ans;
}