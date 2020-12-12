#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

//#define int                long long int
#define jaldichal          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb                 push_back
#define mk                 make_pair
#define R                  return
#define line               "\n"
#define tracearray(arr,n)  cout<<"Values in array: ";for(int i=0;i<n;i++)cout<<arr[i]<<space;cout<<line
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace(x) cout << '>' << #x << ':' << (x) << "\n"
#define space              " "
#define all(x)             x.begin(),x.end()
#define w(x)               int x;cin>>x;for(int i=1;i<=x;i++)
#define vi                 vector<int>
#define setbits(x)         __builtin_popcountll(x)
#define ll                 long long
#define fi                 first
#define se                 second
#define print(i,ans)       cout<<"Case #"<<i<<": "<<ans<<line

/* stuff you should look for
	* special cases (n=1?)
	* doing something instead of nothing and stay organized
	* try solving problem C instead of B.
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
vector<vector<int> > v;
set<pair<int, int > > s;
bool *visited;

void recursion(int node, int Lpartition, int Rpartition) {
	// cout << "?";
	if (visited[node] == 1 || v[node].size() > 2 || Lpartition <= 0 || Rpartition <= 0 || Lpartition > Rpartition) {
		return;
	}
	visited[node] = 1;
	s.insert({Lpartition, Rpartition});
	//cout << node << line;
	for (auto x : v[node]) {

		recursion(x, Lpartition + 1, Rpartition - 1);

	}
	// if (visited[v[node][0]] == 0) {
	// 	recursion(v[node][0], Lpartition + 1, Rpartition - 1);
	// }
	// else if (visited[v[node][1]] == 0) {
	// 	recursion(v[node][1], Lpartition + 1, Rpartition - 1);
	// }
}


void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	v.resize(n);
	visited = new bool[n]();
	for (int i = 0 ; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	// int j = 0;
	// for (auto x : v) {
	// 	cout << j  << "-> ";
	// 	for (auto xx : x) {
	// 		cout << xx << space;
	// 	}
	// 	cout << line; j++;
	// }
	int i = 0 ;
	//recursion(0, 1, n - 2);
	for (auto x : v) {
		if (x.size() == 1 && visited[i] == 0) {
			recursion(i, 1, n - 2);
		}
		i++;
	}
//	int ans = 0;
	bool unfortunate = 0;
	for (auto x : s) {
		if (x.fi == x.se) {
			unfortunate = 1;
			break;
		}
	}
	vector<pair<int, int> > ans;
	if (unfortunate) {
		cout << s.size() * 2  - 1 << line;
		for (auto x : s) {
			ans.pb({x.fi, x.se});
			//	cout << x.fi << space << x.se << line;
		}
		for (auto x : s) {
			if (x.fi == x.se)continue;

			ans.pb({x.se, x.fi});
			//cout << x.se << space << x.fi << line;
		}
		sort(all(ans));
		for (auto x : ans) {
			cout << x.fi << space << x.se << line;
		}
	}
	else {
		cout << 2 * s.size() << line;
		for (auto x : s) {
			ans.pb({x.fi, x.se}); //cout << x.fi << space << x.se << line;
		}
		for (auto x : s) {
			ans.pb({x.se, x.fi}); //cout << x.se << space << x.fi << line;
		}
		sort(all(ans));
		for (auto x : ans) {
			cout << x.fi << space << x.se << line;
		}
	}
}

signed main()
{
	jaldichal
	int x = 1;
	//cin>>x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}