#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;

int power2(int a, int b)
{
	if (b == 0)
		return 1;
	int sr = power2(a, b / 2) % mod;
	int r = (sr * sr) % mod;
	if (b % 2 == 1)
		r = (a * r) % mod;
	return r;
}


signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << power2( a, power2(b, c) % mod) % mod << "\n";
	}
}