// Problem: Forming Groups
// URL: https://codeforces.com/problemset/problem/1938/F
// Rating: 2400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
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

const int N = 1100000;
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, a[N], cnt[N];
set<PII> s;
vector<int> ks;
LL p, q; 

LL gcd(LL a, LL b){
	return b > 0 ? gcd(b, a%b) : a;
}


void solve() {
	ks.clear();
	cin >> n; 
	repn(i, 1, n) cin >> a[i];
	int num = n;
	repn(i, 2, n) {
		if (num % i) continue;
		while (num % i == 0) num /= i;
		ks.pb(i);
		if (num == 1) break;
	}
	p = 1;
	q = 0;
	for (auto k : ks) {
		s.clear();
		rep(i, 0, k) cnt[i] = 0;
		repn(i, 1, n) {
			cnt[(i%k)] += a[i];
		}
		rep(i, 0, k) s.insert(mp(cnt[i], i));
		LL p1 = (*s.rbegin()).fi, q1 = (*s.begin()).fi;
		if (p * q1 > p1 * q) {
			p = p1; q = q1;
		}
		repn(i, 2, n) {
			int id1 = (i - 1) % k, id2 = i % k;
			auto it1 = s.lower_bound(mp(cnt[id1], id1)), it2 = s.lower_bound(mp(cnt[id2], id2)); 
			cnt[id1] += a[i] - a[1];
			cnt[id2] += a[1] - a[i];
//			cout << i << " \n";
//			rep(j, 0, k) cout << cnt[j] << " " << j << "\n";
			s.erase(it1); s.erase(it2);
			s.insert(mp(cnt[id1], id1));
			s.insert(mp(cnt[id2], id2));
			LL p1 = (*s.rbegin()).fi, q1 = (*s.begin()).fi;
			if (p * q1 > p1 * q) {
				p = p1; q = q1;
			}
		}
	}
	LL g = gcd(p, q);
	p /= g;
	q /= g;
	cout << p << " " << q << "\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();	
	return 0;
}