#include<bits/stdc++.h>
using namespace std;

#define int long long int
int n;
int *a;
map<int, int> mp;
int ans;



signed main() {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		int d = ((sum % n) + n) % n;
		if (mp.find(d) != mp.end()) {
			ans += mp[d];
		}
		if (sum % n == 0)ans++;
		mp[((sum % n) + n) % n]++;

	}
	cout << ans;
}