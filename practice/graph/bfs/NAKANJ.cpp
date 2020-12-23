#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

//#define int                long long int
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
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = { -1, 1, 1, -1, 2, -2, 2, -2};

V<V<pair<int, int>> > adj(65);

bool check(int x, int y, int n, int m) {
	if (x + n >= 1 && x + n <= 8 && y + m >= 1 && y + m <= 8)return 1;
	return 0;
}
void build_graph() {

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			for (int k = 0; k < 8; k++) {
				if (check(i, j, dx[k], dy[k]))
					adj[(i - 1) * 8 + j].pb({i + dx[k], j + dy[k]});
			}
		}
	}
}
void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	string s, t;
	cin >> s >> t;
	int x1, y1, x2, y2;
	if (s == t) {
		cout << "0" << line; R;
	}
	x1 = s[0] - 'a' + 1;
	y1 = s[1] - '0';
	x2 = t[0] - 'a' + 1;
	y2 = t[1] - '0';
	queue<pair<int, int> > q;
	int used[9][9] = {0};
	int d[9][9] = {0};

	q.push({x1, y1});
	used[x1][y1] = true;
	// cout << adj;
	// for (int i = 1; i <= 8; i++) {
	// 	for (int j = 1; j <= 8; j++) {
	// 		cout << i << space << j << "-> ";
	// 		for (auto x : adj[(i - 1) * 8 + j])
	// 			cout << x << "   ";
	// 		cout << line;
	// 	}
	// }
	while (!q.empty()) {
		pair<int, int>  v = q.front();
		q.pop();
		if (used[x2][y2])break;
		for (pair<int, int>  u : adj[(v.fi - 1) * 8 + v.se]) {
			if (!used[u.fi][u.se]) {
				used[u.fi][u.se] = true;
				q.push(u);
				d[u.fi][u.se] = d[v.fi][v.se] + 1;
			}
		}
	}
	cout << d[x2][y2] << line; R;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x = 1;
	build_graph();
	cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}