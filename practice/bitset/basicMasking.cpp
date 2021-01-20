


// for (int mask = 0 ; mask < (1 << n); mask++) {
// 	for (int i = 0 ; i < n; i++) {
// 		if (mask & (1 << i)) {
// 			//some operation!!
// 		}
// 	}
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
	int a = 10;

	cout << __builtin_clz(a);
}