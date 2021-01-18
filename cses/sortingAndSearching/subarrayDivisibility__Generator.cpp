#include<bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randNo(int lower_limit, int upper_limit) {

	return lower_limit + rng() % (upper_limit - lower_limit);
}

int N = 1000;

int main() {
	int n = randNo(1, 100);

	//To generate a random array
	int a[n];
	for (int i = 0; i < n; i++) a[i] = randNo(-N, -1);
	cout << n << endl;
	for (int i = 0 ; i < n; i++)cout << a[i] << " ";
}