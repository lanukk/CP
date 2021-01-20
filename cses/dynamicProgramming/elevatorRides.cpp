#include<bits/stdc++.h>
using namespace std;

int n;
int *a;
int w;

//worst answer can be 'n' which is atmax = 20

//i wanna use something related to bitmask!!

//THIS PROBLEM IS LIKE COMBINING CELLS! To form minimum number of cells!

//like combining cell 1 and xth cell!
#define INF 1e9
int dp[21][(1 << 21)];

int recursion(int i, int mask) {
	if (mask == 0)
		return 0;


	if (dp[i][mask] != -1)
		return dp[i][mask];

	int ans = INF;

	for (int d = 1; d < (1 << n); d++) {
		if ((mask | d) != mask)continue;
		long long int sum = 0;

		for (int j = 0 ; j < n; j++) {
			if (d & (1 << j))
				sum += a[j];
		}

		if (sum > w)
			continue;
		ans = min(ans, 1 + recursion(i + 1, (mask) ^ (d)));
	}

	return dp[i][mask] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> w;
	a = new int[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	cout << recursion(0, (1 << n) - 1) << endl;

	return 0;
}