// Problem: Switches
// URL: https://codeforces.com/gym/102920/problem/J
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

const int N = 510;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, a[N][N + N];
void gaussian(int n) {
	repn(i, 1, n) {
		int pos = -1;
		repn(j, i, n) {
			if (a[j][i] == 1) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			cout << "-1\n";
			exit(0);
		}
		repn(j, 1, n + n) swap(a[i][j], a[pos][j]);
		repn(j, 1, n) {
			if (a[j][i] && j != i) {
				repn(k, 1, n + n) a[j][k] ^= a[i][k];
			}
		}
	}
}
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) repn(j, 1, n) cin >> a[i][j];
	repn(i, 1, n) a[i][n + i] = 1;
	gaussian(n);
	repn(i, 1, n) {
		int flag = 0;
		repn(j, 1, n) {
			if (a[i][j + n]) {
				if (flag) cout << " ";
				flag = 1;
				cout << j;
			}
		}
		cout << "\n";
	}
	return 0;
}