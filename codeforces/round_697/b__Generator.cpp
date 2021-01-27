#include<bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randNo(int lower_limit, int upper_limit) {

	return lower_limit + rng() % (upper_limit - lower_limit);
}

int N = 1000000;

int main() {
	int n = randNo(1, N);
	cout << n;
}