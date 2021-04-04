#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

#define int long long int
// int power(int a, int b)
// {
//     if(b==0)
//         return 1;

//     int sr=power(a,b>>1);

//     int r=sr*sr;

//     if(b&1)
//       r=a*r;


//        return r;

// }

int power(int a, int b) {

	if (b == 0) {
		return 1;
	}

	int small_result = power(a, b / 2) ;

	int r = (small_result % mod * small_result % mod) % mod;

	if (b % 2 == 1)
	{
		r = (a * r) % mod;
		if (r < 0)r += mod;
	}
	else {
		if (r < 0)r += mod;
	}
	return r ;
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int k  = power(a, b);
		while (k < 0)k += mod;
		cout << k  << "\n";
	}
}