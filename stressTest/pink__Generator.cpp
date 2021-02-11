#include <bits/stdc++.h>

using namespace std;

const int N = 25;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randNo(int lower_limit, int upper_limit) {

	if (upper_limit - lower_limit == 0) {
		return 0;
	}
	return lower_limit + rng() % (upper_limit - lower_limit);
}
int32_t main() {

	//generating n
	int n = randNo(1, 10001);
	int k = randNo(1, 10001);
	//To generate a random array
	int a[n];
	for (int i = 0 ; i < n; i++)a[i] = randNo(1, 1001);
	cout << n << " " << k << "\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}