// Problem: Journey to Un'Goro
// URL: https://codeforces.com/gym/103202/problem/D
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

LL n;
int mx, cnt;
char s[N];
void dfs(int x, int n0, int n1, int pre) {
	if (n0 > mx || n1 > mx) return;
	if (x == n) {
		printf("%s\n", s);
		cnt++;
		if (cnt == 100) exit(0);
		return;
	}
	s[x] = 'b';
	dfs(x + 1, n0 + (pre ^ 1), n1 + pre, pre);
	s[x] = 'r';
	pre ^= 1;
	dfs(x + 1, n0 + (pre ^ 1), n1 + pre, pre);
}
int main()
{
	IO;
	cin >> n;
	LL ans = ((n + 1) / 2) * ((n + 2) / 2);
	printf("%lld\n", ans);
	mx = n / 2 + 1;
	dfs(0, 1, 0, 0);
	return 0;
}