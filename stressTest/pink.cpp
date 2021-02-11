#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define int                long long int
#define jaldichal          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb                 push_back
#define mk                 make_pair
#define R                  return
#define line               "\n"
#define space              " "
#define all(x)             x.begin(),x.end()
#define w(x)               int x;cin>>x;for(int i=1;i<=x;i++)
#define vi                 vector<int>
#define setbits(x)         __builtin_popcountll(x)
#define ll                 long long

int n, m;

int recursion(int a[], int K, int i, int previous_taken, int* dp) {

	if (i >= n) {
		return 0;
	}


	if (dp[i] != -1) {
		return dp[i];
	}
	int res = INT_MAX;
	for (int j = i + 1; j <= i + K && j < n; j++) {
		res = min(res, max(previous_taken, a[j]) - min(previous_taken, a[j]) + recursion(a, K, j, a[j], dp));
	}
	if (res == INT_MAX)
		res = 0;
	dp[i] = res;
	return  res;
}


void solve()
{
	cin >> n;
	int a[n];
	int K; cin >> K;
	int dp[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = -1;
	}

	int ans = recursion(a, K, 0, a[0], dp);
	cout << ans << line;
}

signed main()
{
	jaldichal
	solve();

	return 0;
}