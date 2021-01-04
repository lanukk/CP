#include<bits/stdc++.h>
using namespace std;

int n;
int *a;

int dp[200011];
int recursion(int i) {
	if (i == n) {
		return 0;
	}
	if (dp[i] != -1) {
		return dp[i];
	}
	int count = 1;
	for (int j = i + 1; j < n; j++) {
		if (a[j] > a[i]) {
			count = max(count, 1 + recursion(j));
		}
	}
	return dp[i] = count;
}

int main() {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, recursion(i));
	}
	cout << ans;
}