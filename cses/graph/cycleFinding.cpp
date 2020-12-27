#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define pb                 push_back
#define mk                 make_pair
#define R                  return
#define line               "\n"
#define space              " "
#define all(x)             x.begin(),x.end()
#define V 				   vector
#define M 				   map
#define ll                 long long
#define fi                 first
#define se                 second
#define print(i,ans)       cout<<"Case #"<<i<<": "<<ans<<line
#define f(a,b,c)           for(int i = a; i < b ;i+=c)
#define fr(a,b,c)          for(int i = a; i >=b ; i = i - c)

//trace
#define tracegraph(v) 	   cout<<#v<<line;int iiii=0;for(auto &x : v){cout<<iiii<<"-> ";for(auto &xx : x)cout<<xx<<" ";cout<<endl;iiii++;}cout<<"---------------"<<line;
#define traceset(s)        cout<<#s<<line;for(auto &x: s)cout<<x<<space;cout<<"---------------"<<line;
#define tracevector(v)     cout<<#v<<line;for(auto &x: v)cout<<x<<" ";cout<<line;cout<<"---------------"<<line;
#define tracemap(mp)       cout<<#mp<<line;for(auto &x: mp){cout<<x.fi<<" "<<x.se<<line;}cout<<"---------------"<<line;
#define tracearray(arr,n)  cout<<#arr<<line;for(int i=0;i<n;i++)cout<<arr[i]<<space;cout<<line
#define trace4(a,b,c,d)    cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define trace3(a,b,c)      cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace2(x,y)        cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace(x)           cout << '>' << #x << ':' << (x) << "\n"


//operator overload
//pair input
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) {istream >> p.first >> p.second; return istream; }
template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) {ostream << p.first << " " << p.second; return ostream; }
//vector operations
template<typename T> istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v) cin >> it; return istream; }
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) {for (auto &it : c) cout << it << " "; return ostream; }
//max minn
template <typename T> T MIN(T first) { return first; } template <typename T, typename... Args> T MIN(T first, Args... args) { return min(first, MIN(args...)); }
template <typename T> T MAX(T first) { return first; } template <typename T, typename... Args> T MAX(T first, Args... args) { return max(first, MAX(args...)); }
/* stuff you should look for
	* special cases (n=1?)
	* doing something instead of nothing and stay organized
	* try solving problem C instead of B.
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* Never Think of BINARY SEARCH (NEVER EVER)
*/
#define int                long long int
struct edge {
	int a, b, cost;
};

V<V<pair<int, int> > > adj;
V<edge> e; V<int> d;


const int mod = LLONG_MAX;
V<int> order;
V<int> visited;



void dfs(int v) {
	visited[v] = 1;
	for (pair<int, int> p : adj[v]) {
		if (!visited[p.fi])dfs(p.fi);
	}
	order.pb(v);
}
V<int> parent;
V<int> ans;

bool z = 0;
void dfs2(int v) {
	visited[v] = 1;
	if (z)return;
	for (pair<int, int> x : adj[v]) {
		int p = x.fi;
		if (z)return;
		if (visited[p] == 1) {
			z = 1;
			int curr = v;
			ans.pb(p);
			while (curr != -1) {
				ans.pb(curr);
				curr = parent[curr];
			}
			return;
		} if (z)return;
		if ( visited[p] == 0)
		{
			parent[p] = v;
			dfs2(p);
		}
	}
	visited[v]  = 2;
}

void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	cin >> n;
	int m;
	cin >> m;
	adj.resize(n + 1);
	e.reserve(m);
	for (int i = 0; i < m; i++) {
		edge x;
		cin >> x.a >> x.b >> x.cost;
		e.pb(x);
		adj[x.a].pb({x.b, x.cost});
	}
	visited.assign(n + 1, 0);
	for (int i = 1 ; i <= n; i++) {
		if (!visited[i])dfs(i);
	}
	int s = order[order.size() - 1];

	d.assign(n + 1, mod);
	d[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0 ; j < m; j++) {
			if (d[e[j].a] < mod) {
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = d[e[j].a] + e[j].cost;
				}
			}
		}
	}
	tracegraph(adj);
	//cout << order << line;
	V<int> check;

	for (int j = 0 ; j < m; j++) {
		if (d[e[j].a] < mod) {
			if (d[e[j].b] > d[e[j].a] + e[j].cost) {
				//d[e[j].b] = d[e[j].a] + e[j].cost;
				check.pb(e[j].b);
			}
		}
	}
	if (check.size() == 0) {
		cout << "NO"; R;
	} parent.assign(n + 1, 0);
	visited.assign(n + 1, 0);
	for (int X : check) {
		if (z)break;
		if (!visited[X]) {
			parent[X] = -1;
			dfs2(X);
		}
	}
	cout << check << line;
	reverse(all(ans));
	cout << "YES";
	cout << line << ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x = 1;
	//cin>>x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}