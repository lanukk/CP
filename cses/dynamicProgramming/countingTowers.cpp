#include<bits/stdc++.h>
using namespace std;

int n;
int recursion(int i) {
	if (i == 0) {
		return 1;
	}
	int sum = 0;
	for (int j = 1; j <= i; j++) {
		if (i - j >= 0 )
			sum += recursion(i - j);
	}
	return sum;
}
int main() {
	n = 3;
	cout << recursion(n);
}