#include<bits/stdc++.h>
using namespace std;



int n, m;
char a[1010][1010];
bool visited[1010][1010];


struct node {
	int x, y;
};

node parent[1010][1010];

node start;
node e;

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B')e.x = i, e.y = j;
			if (a[i][j] == 'A')start.x = i, start.y = j;
		}
	}

	visited[start.x][start.y] = 1;
	parent[start.x][start.y].x = -1;
	parent[start.x][start.y].y = -1;

	queue<node> q;
	q.push(start);

	while (!q.empty()) {
		node f = q.front();
		q.pop();
		if (f.x == e.x && f.y == e.y) {
			break;
		}
		for (int i = 0 ; i < 4; i ++ ) {
			int u = f.x + dx[i];
			int k = f.y + dy[i];
			if (u >= n || k >= m || u < 0 || k < 0 || visited[u][k] == 1)
				continue;

			if (a[u][k] != '#') {
				parent[u][k] = f;
				node z ;
				z.x = u;
				z.y = k;
				visited[u][k] = 1;
				q.push(z);
			}
		}
	}
	if (visited[e.x][e.y] == 0)
	{
		cout << "NO";
		return 0;
	}
	string ans = "";
	int i = e.x;
	int j = e.y;
	while (parent[i][j].x != -1 && parent[i][j].y != -1) {
		if (parent[i][j].x == i) {
			int d = j - parent[i][j].y;
			if (d == 1) {
				ans += 'R';
			}
			else
				ans += 'L';
		}
		else {
			int d = i - parent[i][j].x;
			if (d == 1) {
				ans += 'D';
			}
			else
				ans += 'U';
		}
		int p = parent[i][j].x;
		int l = parent[i][j].y;
		i = p;
		j = l;
	}
	cout << "YES" << endl;
	cout << ans.length() << endl;
	for (int i = ans.length() - 1 ; i >= 0 ; i --)cout << ans[i];
}
