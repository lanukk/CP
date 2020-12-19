vector<vector<int> > adj;
int n;

int SSSP_undirected(int source) {
	queue<int> q;
	vector<bool> used(n);
	vector<int> d(n), p(n);
	q.push
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}
	//PRINT PATH??
	// if (!used[u]) {
	// 	cout << "No path!";
	// } else {
	// 	vector<int> path;
	// 	for (int v = u; v != -1; v = p[v])
	// 		path.push_back(v);
	// 	reverse(path.begin(), path.end());
	// 	cout << "Path: ";
	// 	for (int v : path)
	// 		cout << v << " ";
	// }
}


vector<int> time_in, time_out;  int dfs_timer = 0;   vector<int> color;


void time(int v) {
	time_in[v] = dfs_timer;
	color[v] = 1;
	for (int u : adj[v])
		if (color[u] == 0)
			time(u);
	color[v] = 2;
	time_out[v] = dfs_timer++;
}


vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u])
			dfs(u);
	}
}
