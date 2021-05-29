// Problem: Da Mi Lao Shi Ai Kan De
// URL: https://codeforces.com/gym/104090/problem/F
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
 
const int N = 310000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;


int n, m;
hash<string> T;
set<ull> a;
vector<string> ans;

int main() {
	IO;
	cin >> n;
	string s;
	repn(i, 1, n) {
		cin >> m;
		ans.clear();
		repn(j, 1, m) {
			cin >> s;
			if (a.count(T(s))) continue;
			rep(k, 0, ((int)s.length()) - 2) {
				if (s[k] == 'b' && s[k + 1] == 'i' && s[k + 2] == 'e') {
					ans.pb(s); break;
				}
			}
			a.insert(T(s));
		}
		for (auto x : ans) cout << x << "\n";
		if (ans.size() == 0) cout << "Time to play Genshin Impact, Teacher Rice!\n";
	} 
	return 0;
}

