#include<bits/stdc++.h>
using namespace std;
int n;
int *a;
const int MOD = 1e9 + 7;
int dp[1000001];

// int recursion(int x) {
// 	if (x == 0) {
// 		return 1;
// 	}
// 	if (dp[x] != -1) {
// 		return dp[x];
// 	}
// 	int count = 0;
// 	for (int i = 0; i < n; i++) {
// 		if (x - a[i] >= 0) {
// 			count = (count  + recursion(x - a[i]) % MOD) % MOD;
// 		}
// 	}
// 	return dp[x] = count;
// }
int main() {
	int x;
	cin >> n >> x;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// memset(dp, -1, sizeof(dp));
	// cout << recursion(x) % MOD;

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0) {
				dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
			}
		}
	}
	cout << dp[x] % MOD;
}