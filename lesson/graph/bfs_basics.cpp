//ith node to jth node

//distance of every node by using bfs from a source 'V' (this can only be possible in unweighed graph)

//cses graph - Labyrithm, counting rooms

/*
Applications:

1 - grid
2 - shortest path in unweighed graph.
3 - it is a level order traversal.
*/
#include<bits/stdc++.h>
using namespace std;

int dx[] = { -1, 1,  0, 0};
int dy[] = {  0, 0, -1, 1};

int main() {
	int n, m;
	cin >> n >> m;
	int start_x, start_y;
	bool visited[n][m];

	pair<int, int> parent[n][m];

	char a[n][m];
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'T') {
				start_y = j;
				start_x = i;
			}
			visited[i][j] = 0;
		}
	}

	queue<pair<int, int> > q;
	visited[start_x][start_y] = 1;
	q.push({start_x, start_y});
	bool possible = 0 ;

	parent[start_x][start_y].first = -1;
	parent[start_x][start_y].second = -1;

	int end_x, end_y;


	while (!q.empty()) {
		pair<int, int > f = q.front();
		q.pop();
		if (f.first == n - 1 || f.first == 0 || f.second == m - 1 || f.second == 0) {
			possible = 1;

			end_x = f.first;
			end_y = f.second;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int o = f.first + dx[i];
			int p = f.second + dy[i];
			if (o >= n || o < 0 || p < 0 || p >= m)
				continue;
			if (visited[o][p] == 0 && a[o][p] != '#') {
				q.push({o, p});
				visited[o][p] = 1;
				parent[o][p].first = f.first;
				parent[o][p].second = f.second;
			}
		}
	}
	if (possible) {
		cout << "YES" << endl;
		int i = end_x;
		int j = end_y;

		while (parent[i][j].first != -1 && parent[i][j].second != -1) {
			cout << i << " " << j <<  endl;
			int p, q;
			p = parent[i][j].first;
			q = parent[i][j].second;
			i = p;
			j = q;
		}

	}
	else {
		cout << "NO" << endl;
	}
}