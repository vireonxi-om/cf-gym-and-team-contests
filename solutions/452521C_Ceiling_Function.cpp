// Problem: Ceiling Function
// URL: https://codeforces.com/gym/452521/problem/C
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, k;
set<ull> S;
int ch[N][2], v[N];
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
const ull bias = rand();
ull shift(ull x) {
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}
ull cal(int x) {
	vector<ull> tmp;
	ull res = 1;
	if (ch[x][0]) res += shift(cal(ch[x][0]));
	if (ch[x][1]) res += shift(cal(ch[x][1]) ^ bias);
	return res;
}
int main() {
	IO;
	cin >> n >> k;
	repn(i, 1, n) {
		repn(j, 1, k) ch[j][0] = ch[j][1] = 0;
		int rt;
		repn(j, 1, k) {
			cin >> v[j];
			if (j == 1) rt = 1;
			else {
				int cur = rt;
				while (1) {
					int p = v[j] > v[cur];
					if (ch[cur][p]) cur = ch[cur][p];
					else {
						ch[cur][p] = j;
						break;
					}
				}
			}
		}
		S.insert(cal(1));
	}
	cout << S.size() << "\n";		
	return 0;
}