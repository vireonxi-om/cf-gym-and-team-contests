// Problem: Hanoi
// URL: https://codeforces.com/gym/104114/problem/H
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
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n;
stack<int> s1, s;
vector<PII> ans;

int main() {
	IO;
	cin >> n;
	int num;
	repn(i, 1, n) {
		cin >> num;
		s1.push(num);
	}
	while (!s1.empty()) {
		int nxt = s1.top();
		if (!s.empty() && nxt > s.top()) {
			ans.pb(mp(1, 2));
			s1.pop();
			while (!s.empty() && s.top() < nxt) {
				s1.push(s.top());
				s.pop();
				ans.pb(mp(3, 1));
			}
			ans.pb(mp(2, 3));
			s.push(nxt);
			while (!s1.empty() && s1.top() < s.top()) {
				s.push(s1.top());
				s1.pop();
				ans.pb(mp(1, 3));
			}
		}
		else {
			s.push(nxt);
			s1.pop();
			ans.pb(mp(1, 3));
		}
	}
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.fi << " " << x.se << "\n";
		 
	}
	return 0;
}



