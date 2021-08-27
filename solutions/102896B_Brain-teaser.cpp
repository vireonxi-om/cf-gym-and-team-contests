// Problem: Brain-teaser
// URL: https://codeforces.com/gym/102896/problem/B
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
const int M = 9100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int pp[30], sp[30], num, cp[11], val[30], ys[30], ord[30];
int s[N];
string s1, s2, t;
int last[30], now[30];
map<LL, int> S;
void work() {
	memset(cp, -1, sizeof(cp));
	rep(i, 0, num) val[s[i]] = now[i], cp[now[i]] = i;
	rep(i, 0, 26) if (i < num) sp[i] = 1; else sp[i] = 0;
	LL v1 = 0, v2 = 0;
	rep(i, 0, s1.size()) v1 = v1 * 10 + val[s1[i] - 'A'];
	rep(i, 0, s2.size()) v2 = v2 * 10 + val[s2[i] - 'A'];
	if (val[s1[0] - 'A'] == 0) return;
	if (val[s2[0] - 'A'] == 0) return;
	LL v = v1 + v2;
	int tail = 0;
	LL cval = 0;
	while (v) {
		int x = v % 10, nxt;
		v /= 10;
		if (cp[x] != -1) nxt = cp[x];
		else {
			while (sp[tail]) tail++;
			sp[tail] = 1;
			cp[x] = tail;
			nxt = cp[x];
		}
		cval = cval * 11LL + nxt + 1;
	}
	S[cval]++;
}
vector<string> ans;
int main()
{
	// freopen("input.txt", "r", stdin);
	IO;
	cin >> s1 >> s2;
	rep(i, 0, s1.size()) {
		char x = s1[i];
		if (!pp[x - 'A']) pp[x - 'A'] = 1, ord[x - 'A'] = num, s[num++] = x - 'A';
	}
	rep(i, 0, s2.size()) {
		char x = s2[i];
		if (!pp[x - 'A']) pp[x - 'A'] = 1, ord[x - 'A'] = num, s[num++] = x - 'A';
	}
	if (num > 10) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, 0, 10) last[i] = -1, now[i] = i;
	do {
		int flag = 0;
		rep(i, 0, num) if (last[i] != now[i]) flag = 1;
		if (flag) work();
		rep(i, 0, num) last[i] = now[i];
	}while(next_permutation(now, now + 10));
	int q;
	cin >> q;
	while (q--) {
		cin >> t;
		int tail = 0;
		int cur = 1;
		memset(sp, 0, sizeof(sp));
		memset(ys, -1, sizeof(ys));
		rep(i, 0, 26) {
			if (i < num) sp[i] = 1;
			else sp[i] = 0;
			if (pp[i]) ys[i] = ord[i];
		}
		int flag = 0;
		LL cval = 0;
		per(i, 0, t.size()) {
			int x = t[i] - 'A', nxt;
			if (ys[x] != -1) nxt = ys[x];
			else {
				while (sp[tail]) tail++;
				if (tail >= 10) {
					flag = 1;
					break;
				}
				sp[tail] = 1;
				ys[x] = tail;
				nxt = tail;
			}
			cval = cval * 11LL + nxt + 1;
		}
		if (!flag && S[cval] == 1) ans.pb(t);
	}
	cout << ans.size() << "\n";
	for (auto s: ans) {
		cout << s << "\n";
	}
	return 0;
}