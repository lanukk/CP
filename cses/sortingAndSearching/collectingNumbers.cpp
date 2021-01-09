#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
	int n;
	cin >> n;
	int *a = new int[n + 1];
	for (int i = 1 ; i <= n; i++) {
		int x;
		cin >> x;
		a[x] = i;
	}
	int ans = 1 ;
	int maxx = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] < maxx) {
			maxx = a[i];
			ans++;
		}
		maxx = max(a[i], maxx);
	}
	cout << ans;
}