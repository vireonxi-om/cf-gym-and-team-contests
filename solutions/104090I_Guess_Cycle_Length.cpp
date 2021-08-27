// Problem: Guess Cycle Length
// URL: https://codeforces.com/gym/104090/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 11000000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int st, a[N], mx, last;

int ans = 9989212, p[M], xx;
int ask(int x) {
	cout << "walk " << x << endl;
	fflush(stdout);
	int res;
	cin >> res;
	// xx = (xx + x) % ans;
	// return last = p[xx];
	return last = res;
}
const int L = 3333;
map<int, int> S;
void print(int x) {
	cout << "guess " << x << endl;
	fflush(stdout);
	exit(0);
}
int main() {
	IO;
	rep(i, 1, ans) p[i] = i + 1;
	random_shuffle(p + 1, p + ans +1);
	xx = 0;
	repn(i, 1, L) mx = max(mx, ask(rand() % (inf + 1)));
	S[last] = 0;
	repn(i, 1, L) {
		a[i] = ask(1);
		if (S.count(a[i])) print(i - S[a[i]]);
		S[a[i]] = i;
		mx = max(mx, a[i]);
	}
	ask(mx);
	if (S.count(last)) print(L + mx - S[last]);
	repn(i, 1, L) {
		int x = ask(L);
		if (S.count(x)) print(i * L + mx + L - S[x]);
	}
	return 0;
}