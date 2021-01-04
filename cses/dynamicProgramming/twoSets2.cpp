#include<bits/stdc++.h>
using namespace std;

/* Quite tricky problem because we cannot divide dp[n][sum/2] by 2 because
we did "MOD" operation */

int n;
int *a;
int dp[510][250000];

const int MOD = 1e9 + 7;
// int recursion(int i, int x) {
// 	if (x == 0) {
// 		return 1;
// 	}
// 	if (i == n) {
// 		return 0;
// 	}
// 	if (dp[i][x] != -1) {
// 		return dp[i][x];
// 	}
// 	if (x - a[i] >= 0) {
// 		return dp[i][x] = (recursion(i + 1, x - a[i]) % MOD + recursion(i + 1, x) % MOD) % MOD;
// 	}
// 	return dp[i][x] = recursion(i + 1 , x) % MOD;

// }

int main() {
	cin >> n;
	a = new int[n];
	int sum = 0 ;
	//memset(dp, -1, sizeof(dp));
	for (int i = 1 ; i <= n; i++) {
		sum += i;
		a[i - 1] = i;
	}
	if (sum % 2 == 1) {
		cout << "0"; return 0 ;
	}
	// recursion(0, sum / 2) ;
	// // for (int i = 0; i <= n; i++) {
	// // 	for (int j = 0 ; j <= sum / 2; j++) {
	// // 		cout << dp[i][j] << " ";
	// // 	}
	// // 	cout << "\n";
	// // }
	// cout << dp[1][sum / 2] ;

	for (int i = 0 ; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0 ; j <= sum / 2 ; j++) {
			dp[i][j] = dp[i - 1][j] % MOD;
			if (j - a[i - 1] >= 0)
				(dp[i][j] += dp[i - 1][j - a[i - 1]] % MOD) %= MOD;
		}
	}
	cout << dp[n - 1][sum / 2 ];
}