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

void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	int m; cin >> m;
	int count[n][m];
	int ans = 0;
	char a[n][m];
	for (int i = 0 ; i < n; i++)for (int j = 0 ; j < m; j++) {cin >> a[i][j]; if (a[i][j] == '*')ans++;}
	for (int i = 0 ; i < n; i++) {
		count[i][0] = (a[i][0] == '*') ? 1 : 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			count[i][j] = count[i][j - 1] + ((a[i][j] == '*') ? 1 : 0);
		}
	}
	//for (int i = 0; i < n; i++) {for (int j = 0 ; j < m; j++)cout << count[i][j] << space; cout << line;}

	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') {
				// trace2(i, j);
				int l = 1;
				int level_stars = 3;
				int r = i + 1;
				while (j - l >= 0 && j + l < m && r < n) {
					if (j - l == 0) {
						if (count[r][j + l]  == level_stars) {
							ans++;
						}
					}
					else {
						if (count[r][j + l] - count[r][j - l - 1] == level_stars) {
							ans++;
						}
						else
							break;
					}
					l++;
					level_stars += 2;
					r++;
				}
				// for (int k = i + 1; k < n; k++) {
				// 	if (j - l < 0 || j + l >= m)
				// 	{
				// 		//trace(k);
				// 		break;
				// 	}
				// 	bool star = 1;
				// 	for (int h = j - l ; h <= j + l; h++) {
				// 		if (a[k][h] != '*')
				// 		{star = 0; break;}
				// 	}
				// 	if (!star) {
				// 		break;
				// 	}
				// 	ans++;
				// 	l++;
				// }
			}
		}
	}
	cout << ans << line;

}

signed main()
{
	jaldichal
	int x = 1;
	cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}