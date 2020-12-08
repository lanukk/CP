#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define int                long long int
#define jaldichal          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb                 push_back
#define mk                 make_pair
#define R                  return
#define line               "\n"
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


void solve(int input)
{
	int n;
	cin >> n;
	int a[n]; for (int i = 0; i < n; i++)cin >> a[i];
	int c[n];
	int l[n];
	int z = 0;
	for (int i = 0 ; i < n; i++) {
		int count = 0 ;
		int j = i;
		for (; j < n; j++) {
			if (a[j] != a[i]) {
				break;
			}
			count++;
		}
		c[z] = a[i];
		l[z] = count;
		z++;
		i = j - 1;
	}
	n = z;
	int i = 0 ; int j = 0;

	int maxx = INT_MIN;
	int minn = INT_MAX;
	maxx = c[0];
	minn = c[0];
	int ans = l[0];
	int sans = l[0];
	while (j < n) {
		//cout << minn << space << maxx << line;
		ans = max(ans, l[j]);
		if (i == j) {
			j ++;

		}
		else {
			if (c[j] == minn || c[j] == maxx) {
				sans += l[j];
			}
			else if (minn == maxx && abs(minn - c[j]) == 1) {
				sans += l[j];

				minn = min(c[j], minn);
				maxx = max(c[j], maxx);
			}
			else {
				ans = max(ans, sans);
				sans = l[j];
				if (abs(c[j] - c[j - 1]) == 1) {
					sans += l[j - 1];
					minn = min(c[j], c[j - 1]);
					maxx = max(c[j], c[j - 1]);
					i = j - 1;
				}
				else {
					i = j ;
					minn = c[j];
					maxx = c[j];
				}
			}
			j++;
		}
		//cout << minn << space << maxx << line;
	}
	ans = max(ans, sans);
	cout << ans << line;
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