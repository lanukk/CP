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
int dx[] = {0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};

void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	int m;
	cin >> n >> m;
	int a[n][m];
	int used[n][m];
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> a[i][j];
			used[i][j] = 0;
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j  < m - 1; j++) {
			if (a[i][j] < MAX(a[i][j - 1], a[i][j + 1], a[i + 1][j], a[i - 1][j]) && used[i][j] == 0) {
				queue<pair<int, int> > q;
				q.push({i, j});
				int temp[n][m] ;
				memset(temp, 0, sizeof(temp));
				temp[i][j] = 1;
				bool possible = 1;
				while (!q.empty()) {
					pair<int, int > p = q.front();
					q.pop();
					if (p.fi == 0 || p.fi == n - 1 || p.se == 0 || p.se == m - 1) {
						possible = 0;
						break;
					}
					for (int  k = 0 ; k < 4 ; k++) {
						if (p.fi + dx[k] < n && p.fi + dx[k] >= 0 && p.se  + dy[k] < m && p.se + dy[k] >= 0) {
							if (a[p.fi + dx[k]][p.se + dy[k]] <= a[p.fi][p.se] && temp[p.fi + dx[k]][p.se + dy[k]] == 0) {
								temp[p.fi + dx[k]][p.se + dy[k]] = 1;
								q.push({p.fi + dx[k], p.se + dy[k]});
							}
						}
					}
				}

				if (possible) {
					for (int k = 0; k < n; k++) {
						for (int u = 0 ; u < m; u++) {
							if (temp[k][u] == 1) {
								used[k][u] = 1;
							}
						}
					}
				}
			}
		}
	}
	// for (int i = 0  ; i < n; i++) {
	// 	for (int j = 0 ; j < m; j++)cout << used[i][j] << space; cout << line;
	// } cout << line;
	int visited[n][m];
	int ans = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j  < m; j++) {
			if (used[i][j] == 1 && visited[i][j] == 0) {

				int small = INT_MAX;
				int p = i;
				int q = j;

				for (;; q++) {
					if (used[p][q] == 0 )
						break;
					for (int k = 0; k < 4; k ++) {
						if (used[p + dx[k]][q + dy[k]] == 0) {
							small = min(small, a[p + dx[k]][q + dy[k]]);
						}
					}
				}
				q--;
				// cout << p << space << q << line;
				for (;; p++) {
					if (used[p][q] == 0)
						break;
					for (int k = 0; k < 4; k ++) {
						if (used[p + dx[k]][q + dy[k]] == 0) {
							small = min(small, a[p + dx[k]][q + dy[k]]);
						}
					}
				}
				p--;
				for (;; q--) {
					if (used[p][q] == 0)
						break;
					for (int k = 0; k < 4; k ++) {
						if (used[p + dx[k]][q + dy[k]] == 0) {
							small = min(small, a[p + dx[k]][q + dy[k]]);
						}
					}
				}
				q ++ ;
				for (;; p -- ) {
					if (used[p][q] == 0)
						break;
					for (int k = 0; k < 4; k ++) {
						if (used[p + dx[k]][q + dy[k]] == 0) {
							small = min(small, a[p + dx[k]][q + dy[k]]);
						}
					}
				}
				p++;
				//cout << small << line;
				//bfs

				queue<pair<int, int> > que;
				que.push({i, j});
				visited[i][j] = 1;
				// for (int i = 0 ; i  < n; i++) {
				// 	for (int j = 0 ; j < m; j++)cout << visited[i][j] << space;
				// 	cout << line;
				// } cout << line;
				while (!que.empty()) {
					pair<int, int> d = que.front();
					que.pop();
					ans = ans + small - a[d.fi][d.se];
					for (int  k = 0 ; k < 4; k++) {
						if (used[d.fi + dx[k]][d.se + dy[k]] == 1 && visited[d.fi + dx[k]][d.se + dy[k]] == 0) {
							que.push({d.fi + dx[k], d.se + dy[k]});
							visited[d.fi + dx[k]][d.se + dy[k]] = 1;
							//	cout << d.fi + dx[k] << space << d.se + dy[k] << line;
						}
					}
				}

			}
		}
	}

	cout << ans << line;
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