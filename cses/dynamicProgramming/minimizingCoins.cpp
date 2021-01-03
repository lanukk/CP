#include<bits/stdc++.h>
using namespace std;
int *a;
int n;
int INF = 1e9;

int dp[1000001];
// int recursion(int x) {
// 	if (x == 0) {
// 		return 0;
// 	}
// 	if (dp[x] != -1) {
// 		return dp[x];
// 	}
// 	int r = INF;
// 	for (int i = 0; i < n; i++) {
// 		if (x - a[i] >= 0) {
// 			r = min(r, 1 +  recursion(x - a[i]));
// 		}
// 	}
// 	return dp[x] = r;
// }

int main() {
	int  x;
	cin >> n >> x;
	a = new int[n];
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	// memset(dp, -1, sizeof(dp));
	// int ans = recursion(x);
	// if (ans == INF)
	// 	ans = -1;
	// cout << ans;

	dp[0] = 0;
	for (int i = 1 ; i <= 1e6; i++) {
		dp[i] = INF;
	}
	for (int i = 1; i <= x ; i++) {
		for (int j = 0 ; j < n; j++) {
			if (i - a[j] >= 0) {
				dp[i] = min(dp[i - a[j]] + 1, dp[i]);
			}
		}
	}
	if (dp[x] == INF)
		dp[x] = -1;
	cout << dp[x];
}