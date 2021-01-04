#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int *a;

int dp[5010][5010];

int recursion(int l, int r) {
	if (l > r) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	return dp[l][r] = max(a[l] - recursion(l + 1, r), a[r] - recursion(l, r - 1));
}


signed main() {
	cin >> n;
	a = new int[n];
	int sum = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)cin >> a[i], sum += a[i];
	recursion(0, n - 1);

	cout << ((sum + dp[0][n - 1]) / 2);
}