#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int dp[1000001];

// int recursion(int n) {
// 	if (n == 0) {
// 		return 1;
// 	}
// 	if (dp[n] != -1) {
// 		return dp[n];
// 	}
// 	int count = 0;
// 	for (int i = 1; i <= 6; i++) {
// 		if (n - i >= 0) {
// 			count = (count + (recursion(n - i)) % MOD) % MOD;
// 		}
// 	}
// 	return dp[n] = count % MOD;
// }

int main() {
	int n;
	cin >> n;
	//memset(dp, -1, sizeof(dp));
	//cout << recursion(n) % MOD;
	dp[0] = 1 ;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= 6 ; j++) {
			if (i - j >= 0) {
				dp[i] = (dp[i] + dp[i - j]) % MOD;
			}
		}
	}
	cout << dp[n];
}