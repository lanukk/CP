#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int m;
int q;
vector<vector<int>>a;
#define INF 1000000000000000LL
signed main() {
	cin >> n >> m >> q;
	a.resize(n + 1);
	for (int i = 0 ; i <= n; i++)a[i].resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				a[i][j] = 0;
				continue;
			}
			a[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		int w;
		cin >> x >> y >> w;
		a[x][y] = a[y][x] = min(a[y][x], w);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (a[x][y] == INF)a[x][y] = a[y][x] = -1;
		cout << a[x][y] << "\n";
	}

}