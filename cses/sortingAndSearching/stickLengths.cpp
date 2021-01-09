#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n;
int *a;

signed main() {
	cin >> n;
	a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	int ans = 0 ;
	for (int i = 0 ; i < n; i++) {
		ans += abs(a[i] - a[n / 2]);
	}
	cout << ans;
}