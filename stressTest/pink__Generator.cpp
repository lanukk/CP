#include <bits/stdc++.h>

using namespace std;

const int N = 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randNo(int lower_limit, int upper_limit) {

	return lower_limit + rng() % (upper_limit - lower_limit);
}
int32_t main() {

	//generating n
	int n = 8;
	for (int  i = 0; i < n; i++) {
		int a = randNo(1, 1000);
		if (a & 1)cout << '1';
		else
			cout << '0';
	}
}