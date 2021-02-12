//ssenseeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include<bits/stdc++.h>
#define startt ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef unsigned long long ull;
typedef long long  ll;
#define MOD 1000000007
#define MX 1000000000
#define NMAX 100005
#define MXL 1000000000000000000
#define PI 3.14159265
#define pb push_back
using namespace std;
#define sc second
#define endl '\n'
#define fr first

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dp[10001];
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		dp[i] = MX;
		for (int j = i - 1; j >= max(0, i - k); j--)
		{
			dp[i] = min(dp[i], dp[j] + abs(a[j] - a[i]));
		}
	}
	cout << dp[n - 1] << endl;;
}