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
	int k;
	cin >> n >> k;
	string s, t;
	string a, b;
	cin >> s >> t ;
	int c1[26] = {0}, c2[26] = {0};
	for (int i = 0 ; i < n; i++) {
		c1[s[i] - 'a']++;
		c2[t[i] - 'a']++;
	}
	a = "", b = "";
	for (int i = 0 ; i < 26; i++) {
		if (c1[i] > c2[i]) {
			a.append(c1[i] - c2[i], (char)(97 + i));
		}
		else if (c2[i] > c1[i])
			b.append(c2[i] - c1[i], (char)(97 + i));
	}
	n = a.length();
	for (int i = 0 ; i < n; i++) {
		if (a[i] != b[i]) {
			if (a[i] > b[i]) {
				cout << "No" << line; R;
			}
			if (i + k - 1 < n) {
				if (a[i] != a[i + k - 1]) {
					cout << "No" << line; R;
				}
				int j = i;
				int lmao = -1;
				int d = (int)(b[j] - a[j]);
				for (; j < i + k; j++) {
					a[j] = (char)(a[j] + d);
					if (a[j] < b[j] && lmao == -1) {
						lmao = j;
					}
					if (a[j] > b[j]) {
						cout << "No" << line; R;
					}
				}
				if (lmao != -1)
					i = lmao - 1;
				else
					i = i + k - 1;
			}
			else {
				cout << "No" << line; R;
			}
		}
	}


	cout << "Yes" << line; R;
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