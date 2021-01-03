#include<bits/stdc++.h>
using namespace std;

int n;
int *price, *page;

// int dp[1001][100001];

// int recursion(int i, int x) {
// 	if (x == 0 || i == n) {
// 		return 0;
// 	}
// 	if (dp[i][x] != -1) {
// 		return dp[i][x];
// 	}
// 	if (x - price[i] >= 0 ) {
// 		return dp[i][x] = max(page[i] + recursion(i + 1, x - price[i]), recursion(i + 1, x));
// 	}
// 	return dp[i][x] = recursion(i + 1, x);
// }

int main() {
	cin >> n;
	int x;
	cin >> x;
	price = new int[n];
	page = new int[n];
	for (int i = 0 ; i < n; i++)cin >> price[i];
	for (int i = 0 ; i < n; i++)cin >> page[i];
	// memset(dp, -1, sizeof(dp));
	vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0 ; j <= x ; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - price[i - 1] >= 0) {
				dp[i][j] = max(dp[i][j], page[i - 1] + dp[i - 1][j - price[i - 1]]);
			}
		}
	}
	cout << dp[n][x];
}