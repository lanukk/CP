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
	string s;
	cin >> s;
	int ans = 1e10;
	int count = 0;
	if (n == 1 ) {
		if (s == '0')
			cout << ans << line;
		else
			cout << 2 * ans << line;
	}
	else if (n == 2 && ((s[0] == '1' && s[1] == '1') || (s[0] == '1' && s[1] == '0'))) {
		cout << ans << line;
	}
	else if (n == 3 && s == "110") {
		cout << ans << line;
	}
	else {
		if (n == 2) {
			cout << ans - 1 << line; R;
		}
		else {
			if (s[0] == '0') {
				n = ceil((n - 1) / 3.0);
				cout << ans - n << line;
			}
			else if (s[1] == '0') {
				n = ceil((n - 2) / 3.0);

				cout << ans - n << line;
			}
			else {
				n = ceil((n - 3) / 3.0);
				cout << ans - n << line;

			}
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