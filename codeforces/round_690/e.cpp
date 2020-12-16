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
int MOD = 1e9 + 7;

const int mod = 1e9 + 7;
int modpow(int x, int n, int m = MOD)
{
	if (n == 0) return 1 % m;
	long long u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1) u = (u * x) % m;
	return u;
}

int modinv(int x, int m = MOD)
{
	return modpow(x, m - 2, m);
}
int mul(int x, int y)
{
	return (x * y) % MOD;
}

constexpr int N = 2e5;

int f[N + 1], fi[N + 1];

void preSolve()
{
	f[0] = f[1] = fi[0] = fi[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		f[i] = mul(f[i - 1], i);
		fi[i] = mul(fi[i - 1], modinv(i));
	}
}

int nCr(int n, int r)
{
	if (r > n) return 0;
	return mul(f[n], mul(fi[r], fi[n - r]));
}

void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	int m, k;
	cin >> m >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n < m) {
		cout << "0" << line; R;
	}
	sort(a, a + n);
	int x = 0 ;
	while (x < n && a[0] == a[x]) {
		x++;
	}
	int prefix[n];
	prefix[0] = x;
	int r[n];
	r[0] = a[0];
	int z = 1;
	for (int i = x; i < n; i++) {
		int c = 0;
		int j = i ;
		while (j < n && a[i] == a[j]) {
			c++;
			j++;
		}
		prefix[z] = c + prefix[z - 1];
		r[z] = a[i];
		i = j - 1;
		z++;
	}
	n = z;
	int ans = 0;
	int p = lower_bound(r, r + n, r[0] + k) - r;
	//cout << r[0] + k << line;
	// tracearray(r, n);
	// tracearray(prefix, n);
	if (p < n && r[p] == r[0] + k) {
		ans = (ans + nCr(prefix[p] , m)) % mod 	 ;
		if (prefix[p] - prefix[0] >= m) {
			ans = (ans - (nCr(prefix[p] - prefix[0], m))) % mod;
		}
	}
	else  {
		ans = (ans + nCr(prefix[p - 1], m)) % mod;
		if (prefix[p - 1] - prefix[0] >= m) {
			ans = (ans - (nCr(prefix[p] - prefix[0], m))) % mod;
		}
	}
	//cout << ans << line;
	for (int i = 1 ; i < n; i++) {
		int index = lower_bound(r, r + n, r[i] + k ) - r;
		if (index < n && r[index] == r[i] + k) {
			if (prefix[index] - prefix[i - 1] >= m)
				ans = ( ans + nCr(prefix[index] - prefix[i - 1], m)) % mod;
			if (prefix[index] - prefix[i] >= m) {
				ans = (ans - nCr(prefix[index] - prefix[i], m)) % mod;
			}
		}
		else {
			if (prefix[index - 1] - prefix[i - 1] >= m)
				ans = (ans + nCr(prefix[index - 1] - prefix[i - 1] , m)) % mod;
			if (prefix[index - 1] - prefix[i] >= m) {
				ans = (ans - nCr(prefix[index] - prefix[i], m)) % mod;
			}
		}
		//cout << line;
	}
	cout << ans << line;
}

signed main()
{
	jaldichal
	preSolve();
	int x = 1;
	cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}