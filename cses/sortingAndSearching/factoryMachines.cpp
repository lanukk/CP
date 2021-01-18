#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long int
int *a;
int n;
int t;

bool check(int x) {
    int count = 0 ;
    for (int i = 0 ; i < n; i++) {
        count += x / a[i];
    }
    if (count >= t)return 1;
    return 0;
}

signed main() {
    cin >> n;
    cin >> t;
    a = new int [n];
    for (int i = 0; i < n; i++)cin >> a[i];
    int l = 1; int r = 1e18;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        }
        else
            l = mid + 1 ;
    }
    cout << l;
}