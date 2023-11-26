// Problem: Tournament
// URL: https://codeforces.com/gym/104270/problem/F
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
typedef long double LD;

const int N = 110000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, k;
int a[1100][1100];

void solve() {
	cin >> n >> k;
	int bs = 1, t = 0;
	repn(i, 1, n) {
		bs *= 2;
		if (n % bs) break;
		t ++;
	}
	bs /= 2;
	k ++;
	if (k > bs) {
		cout << "Impossible\n";
		return;
	}
	int b = 2;
	repn(i, 2, k) {
		if (i > b) b *= 2;
		a[i][1] = i; a[i][i] = 1;
		rep(j, 2, i) {
			a[i][j] = a[j][i];
			a[i][a[j][i]] = j;
		}	
		repn(j, b + 1, n) a[i][j] = a[i][j - b] + b;
	}
	repn(i, 2, k) {
		repn(j, 1, n) {
			cout << a[i][j];
			if (j != n) cout << " ";
			else cout << "\n"; 
		}
	}
}

int main() {
	IO; 
	int t;
	cin >> t;
	repn(i, 1, t) solve(); 
	return 0;
}

