#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n;
int *a;
signed main() {
	cin >> n;
	a = new int[n];
	for (int i = 0 ; i < n; i++)cin >> a[i];
	int ans = -1e13;
	int sum = 0 ;
	for (int i = 0; i < n; i++) {
		if (sum < 0) sum = 0;
		sum += a[i];
		ans = max(ans, sum);
	}
	cout << ans;
}