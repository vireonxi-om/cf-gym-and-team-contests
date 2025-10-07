// Problem: Cypher
// URL: https://codeforces.com/gym/103145/problem/B
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int T, n, d;
int ys[26], p[110], f[110];
string s[110], t, ans;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, 26)
			ys[i] = i;
		repn(i, 1, n) {
			cin >> t;
			swap(ys[t[0] - 'A'], ys[t[1] -'A']);
		}
		cin >> d;
		repn(i, 1, d) cin >> s[i];
		repn(i, 1, d) cin >> p[i];
		cin >> t;
		rep(i, 0, 26)
			f[t[i] - 'A'] = i;
		int q;
		cin >> q;
		while (q--) {
			cin >> t;
			rep(i, 0, t.size()) {
				p[1]++;
				int now = 1;
				while (now <= d && p[now] == 26) p[now] = 0, p[now + 1]++, now++;
				int x = t[i] - 'A';
				
				x = ys[x];
				repn(j, 1, d) {
					int y = (x + p[j]) % 26;
					int pos = 0;
					rep(k, 0, 26) {
						if (s[j][(k + p[j]) % 26] - 'A' == y) {
							pos = k;
							break;
						}
					}
					x = pos;
				}
				x = f[x];
				pern(j, 1, d) {
					int y = s[j][(x + p[j]) % 26] - 'A';
					int pos = 0;
					rep(k, 0, 26) {
						if ((k + p[j]) % 26 == y) {
							pos = k;
							break;
						}
					}
					x = pos;
				}
				x = ys[x];
				putchar(x + 'A');
			}
			putchar('\n');
		}
	}
				
	return 0;
}