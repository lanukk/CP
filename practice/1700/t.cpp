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
#define tracegraph(v) 	   cout<<#v<<line;int iiii=1;for(auto &x : v){cout<<iiii<<"-> ";for(auto &xx : x)cout<<xx<<" ";cout<<endl;iiii++;}cout<<"---------------"<<line;
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

V<V<int> > adj;
//#define int                long long int

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	int m;
	cin >> n >> m;
	char a[n][m];
	map<pair<int, int>, bool> B, G;
	bool v[n][m];
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B')
				B[ {i, j}] = 1;
			else if (a[i][j] == 'G')
				G[ {i, j}] = 1;
			v[i][j] = 0;
		}
	}
	for (auto x : B) {
		pair<int, int> p = x.first;
		int i = p.first;
		int j = p.second;
		for (int k = 0; k < 4; k ++) {
			int ci = i + dx[k];
			int cj = j + dy[k];
			if (ci < 0 || cj < 0 || cj >= m || ci >= n)continue;
			if (a[ci][cj] != '.')
				continue;
			a[ci][cj] = '#';
		}
	}

	//edge cases

	if (a[n - 1][m - 1] == '#') {
		if (G.size() == 0) {
			cout << "Yes" << line;
			return;
		}
		else if (G.size() >= 0) {
			cout << "No" << line;
			return;
		}
		else if (G.size() == 0 && B.size() == 0) {
			cout << "Yes" << line;
			return;
		}
		else {
			cout << "Yes" << line;
			return;
		}
	}
	else if (a[n - 1][m - 1] == 'B') {
		cout << "No" << line;
		return;
	}

	bool possible = 1;
	queue<pair<int, int> > q;
	v[n - 1][m - 1] = 1;
	q.push({n - 1, m - 1});
	while (!q.empty()) {
		pair<int, int> f = q.front();
		q.pop();
		int i = f.first;
		int j = f.second;
		for (int k = 0 ; k < 4; k ++) {
			int ci = i + dx[k];
			int cj = j + dy[k];
			if (ci < 0 || cj < 0 || cj >= m || ci >= n || v[ci][cj] || a[ci][cj] == '#')
				continue;
			v[ci][cj] = 1;
			q.push({ci, cj});
		}
	}
	// for (int i = 0 ; i < n; i++) {
	// 	for (int j = 0 ; j < m; j++)cout << v[i][j] << ' ';
	// 	cout << line;
	// }

	for (auto x : G) {
		pair<int, int> f = x.first;
		if (!v[f.first][f.second])possible = 0;
	}
	for (auto x : B) {
		pair<int, int> f = x.first;
		if (v[f.first][f.second])possible = 0 ;
	}
	if (possible)cout << "Yes" << line;
	else cout << "No" << line;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x = 1;
	cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}