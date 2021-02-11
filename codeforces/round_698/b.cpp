#include<bits/stdc++.h>
using namespace std;

int d ;
char k;

bool check(int n) {
	string s = to_string(n);
	for (int i = 0 ; i < s.length(); i++) {
		if (s[i] == k) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin >> d;
		if (d == 1) {
			int x;
			for (int i = 0 ; i < n; i++) {
				cin >> x;
				cout << "YES\n";
			}
			continue;
		}
		string m = to_string(d);
		k = m[0];
		for (int i = 0 ; i < n; i++) {
			int z;
			bool flag = 0 ;
			cin >> z;
			for (int j = 0 ; j * d <= z; j++) {
				if (check(z - (j * d))) {
					cout << "YES\n";
					flag = 1;
					break;
				}
			}
			if (!flag)cout << "NO\n";
		}
	}
}