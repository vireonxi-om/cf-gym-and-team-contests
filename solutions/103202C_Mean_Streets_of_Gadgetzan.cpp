// Problem: Mean Streets of Gadgetzan
// URL: https://codeforces.com/gym/103202/problem/C
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
vector<int> f[N];
int du[N], h[N], ans[N], pp[N];
string s;
int cal(string &s) {
	int res = 0;
	for (auto x: s) {
		if (x != '!') {
			res = res * 10 + x - '0';
		}
	}
	return res;
}
queue<PII> que;
PII res[N];
int main()
{
	IO;
	scanf("%d %d", &n, &m);
	repn(i, 1, n) {
		int flag = 0;
		vector<PII> tmp;
		int op = 1, num = 0, cnt = 0;
		while (1) {
			cnt++;
			char x = getchar();
			if (x >= '0' && x <= '9') {
				num = num * 10 + x - '0';
			}
			else if (x == '-' || x == '>') {
				flag = 1;
				num = 0, op = 1;
			}
			else if (x == '!') op = 0;
			else if (x == ' ' || x == '\n' || x == '\r') {
				if (num) {
					tmp.pb(mp(num, op));
					num = 0, op = 1;
				}
			}
			if (cnt > 1 && x == '\n') break;
		}
		if (tmp.size() == 1) {
			que.push(tmp[0]);
		}
		else {
			res[i] = tmp[tmp.size() - 1];
			h[i] = 1;
			du[i] = tmp.size() - 1;
			rep(j, 0, tmp.size() - 1) {
				f[tmp[j].fi].pb(i);
			}
		}
	}
	memset(ans, -1, sizeof(ans));
	int flag = 0;
	while (!que.empty()) {
		PII now = que.front();
		que.pop();
		if (ans[now.fi] != -1) {
			if (now.se != ans[now.fi]) flag = 1;
		}
		else {
			ans[now.fi] = now.se;
			for (auto x: f[now.fi]) {
				du[x]--;
				if (ans[now.fi] == 0) h[x] = 0;
				if (du[x] == 0 && h[x] == 1) {
					que.push(res[x]);
				}
			}
		}
	}
	if (!flag) {
		repn(i, 1, m) {
			if (ans[i] == 1) putchar('T');
			else putchar('F');
		}
		putchar('\n');
	}
	else printf("conflict\n");
	return 0;
}