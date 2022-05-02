// Problem: Oops, It's Yesterday Twice More
// URL: https://codeforces.com/gym/103470/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 210000;
const int M = 110000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;




int main() {
    IO;
    int n, a, b;
    cin >> n >> a >> b;
    int m1 = 0, m2 = 0;
    if (a - 1 > n - a) m1 = 1;
    if (b - 1 > n - b) m2 = 1;
    string ans = "";
    if (m1) rep(i, 1, n) ans += "D";
    else rep(i, 1, n) ans += "U";
    if (m2) rep(i, 1, n) ans += "R";
    else rep(i, 1, n) ans += "L";
    PII cur = mp(1, 1), tar = mp(a, b);
    if (m1) cur.fi = n;
    if (m2) cur.se = n;
    while (cur != tar) {
    	if (cur.fi < tar.fi){
    		ans += "D";
    		cur.fi ++;
		} 
		else if (cur.fi > tar.fi) {
			ans += "U";
			cur.fi --;
		}
		else if (cur.se < tar.se) {
			ans += "R";
			cur.se ++;	
		}
		else {
			ans += "L";
			cur.se --;
		}
	}
	cout << ans << "\n";
    return 0;
}




