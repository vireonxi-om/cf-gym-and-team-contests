// Problem: Fixing Networks
// URL: https://codeforces.com/gym/103119/problem/F
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, d, c;
vector<int> g[N];
void add(int x, int y) {
	g[x].pb(y);
	g[y].pb(x);
}
int main()
{
	IO;
	cin >> n >> d >> c;
	if (d == 0) {
		if (n == c) {
			cout << "Yes\n";
			repn(i, 1, n) cout << "\n";
		}
		else cout << "No\n";
		return 0;
	}
	if (d == 1) {
		if (n == 2 * c) {
			cout << "Yes\n";
			repn(i, 1, n) {
				if (i % 2 == 1) cout << i + 1 << "\n";
				else cout << i - 1 << "\n";
			}
		}
		else cout << "No\n";
		return 0;
	}
	if (c * (d + 1) > n || (n * d) % 2 == 1) cout << "No\n";
	else {
		cout << "Yes\n";
		int cur = 0;
		rep(i, 1, c) {
			repn(j, cur + 1, cur + d + 1)
				repn(k, cur + 1, cur + d + 1)
					if (j != k) g[j].pb(k);
			cur += d + 1;
		}
		int left = n - cur;
		cur++;
		rep(i, 0, left)
			add(cur + i, cur + (i + 1) % left);
		int now = 2;
		for (int i = 3; i + 1 <= d; i += 2) {
			if (now * 2 == left) now++;
			rep(j, 0, left)
				add(cur + j, cur + (j + now) % left);
			now++;
		}
		if (d & 1) {
			for (int i = 0; i < left / 2; i++)
				add(cur + i, cur + (i + left / 2) % left);
		}
				
		
		repn(i, 1, n) sort(all(g[i]));
		repn(i, 1, n) {
			rep(j, 0, (int)g[i].size()) {
				cout << g[i][j];
				if (j != g[i].size() - 1) cout << " ";
				else cout << "\n";
			}
		}
	}
	return 0;
}