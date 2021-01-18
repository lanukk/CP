#include<bits/stdc++.h>
using namespace std;
int *a;
int n;
#define INF 1e9

int dp[10010][5];

int recursion(int i, int prev) {
	if (i == n)return 0;
	if (dp[i][prev] != -1) {
		return dp[i][prev];
	}

	if (a[i] == a[i - 1]) {
		return dp[i][prev] = recursion(i + 1, prev);
	}
	int k = INF ;
	if (a[i] > a[i - 1]) {
		for (int j = 1; j <= prev; j++) {
			k = min(k, recursion(i + 1, j) + 1);
		}
		for (int j = prev + 1; j <= 4; j++) {
			k = min(k, recursion(i + 1, j));
		}
	}
	else {
		for (int j =  prev; j <= 4; j++) {
			k = min(k, 1 + recursion(i + 1, j));
		}
		for (int j = 1; j < prev; j++) {
			k = min(k, recursion(i + 1, j));
		}
	}
	return dp[i][prev] = k;
}


void solve(int number) {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	a = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = INF;
	for (int i = 1; i <= 4; i++) {
		ans = min(ans, recursion(1, i));
	}
	cout << "Case #" << number << ": " << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}