//link :https://codeforces.com/problemset/problem/550/B

#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int *a;
int l, r;
int x;

signed main() {
	cin >> n;
	a = new int[n];
	cin >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int mask = 0 ; mask < (1 << n); mask++) {
		int largest = INT_MIN, smallest = INT_MAX, sum = 0;
		if (__builtin_popcountll(mask) < 2)continue;
		for (int i = 0 ; i < n; i++) {
			if (mask & (1 << i)) {
				largest = max(largest, a[i]);
				smallest = min(smallest, a[i]);
				sum += a[i];
			}
		}
		if (largest - smallest >= x && sum >= l && sum <= r)
			ans++;
	}
	cout << ans;
}