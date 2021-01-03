#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;

int dp[1000001];
// int recursion(int n) {
// 	if (n == 0) {
// 		return 0;
// 	}
// 	if (dp[n] != -1) {
// 		return dp[n];
// 	}
// 	string s = to_string (n);
// 	int r = INF;
// 	for (auto x : s) {
// 		if (x != '0') {
// 			r = min(r, 1 + recursion(n - (x - '0')));
// 		}
// 	}
// 	return dp[n] = r;
// }

int main() {
	int n ;
	cin >> n;
	// memset(dp, -1, sizeof(dp));
	// cout << recursion(n);
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
	}
	dp[0] = 0 ;
	for (int i = 1; i <= n ; i++) {
		string s = to_string(i);
		for (auto x : s) {
			if (x != '0') {
				if (i - (x - '0') >= 0) {
					dp[i] = min(dp[i], 1 + dp[i - (x - '0')]);
				}
			}
		}
	}
	cout << dp[n];
}