#include<bits/stdc++.h>
using namespace std;

int n, m;


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(char a[][1001], int i, int j) {

	a[i][j] = '#';
	for (int k = 0 ; k < 4; k++) {
		if (a[i + dx[k]][j + dy[k]] == '.') {
			dfs(a, i + dx[k], j + dy[k]);
		}
	}
}

int main() {
	cin >> n >> m;
	char a[1001][1001];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			if (a[i][j] == '.') {
				ans++;
				dfs(a, i, j);
			}
		}
	}
	cout << ans;
}