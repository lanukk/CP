#include<bits/stdc++.h>
using namespace std;

char a[1028][1028];

bool visited[1028][1028];

pair<int, int> parent[1028][1028];

int n;
int m;

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool possible;
queue<pair<int, int> > q;

pair<int, int> start;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'M') {
				q.push({i, j});
				visited[i][j] = 1;
				a[i][j] = '#';
			}
			else if (a[i][j] == 'A') {
				start = {i, j};
				visited[i][j] = 1;

			}
		}
	}
	q.push(start);
	while (!q.empty()) {
		pair<int, int> f = q.front();
		q.pop();
		if (a[f.first][f.second] == '#') {

		}
	}
}