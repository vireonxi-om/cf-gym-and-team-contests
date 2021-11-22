// Problem: Average Rank
// URL: https://codeforces.com/gym/102500/problem/A
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 410000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const int INF = 1e8;
const double eps = 1e-9;

int n, w, sc[N];
set<int> S[M], sp;
double v[N], lz[M];
int main() {
	IO;
	cin >> n >> w;
	repn(i, 1, n) S[0].insert(i), sc[i] = 0;
	sp.insert(0);
	repn(i, 1, w) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			S[sc[x]].erase(x);
			v[x] += lz[sc[x]];
			S[sc[x] + 1].insert(x);
			v[x] -= lz[sc[x] + 1];
			if (!sp.count(sc[x] + 1)) sp.insert(sc[x] + 1);
			if (S[sc[x]].size() == 0) sp.erase(sc[x]);
			sc[x]++;
		}
		LL now = n;
		for (auto idx: sp) {
			now -= S[idx].size();
			lz[idx] += now + 1;
		}
	}
	repn(i, 1, n) {
		v[i] += lz[sc[i]];
		printf("%.10f\n", v[i] / (double)w);
	}
	return 0;
}