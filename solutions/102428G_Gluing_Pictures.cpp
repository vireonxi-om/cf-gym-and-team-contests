// Problem: Gluing Pictures
// URL: https://codeforces.com/gym/102428/problem/G
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

const int N = 2100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

const int maxn = 2100000;
struct SAM {
	struct node {
		int ch[26];
		int par, val;
		node (int val = 0): par(0), val(val) {
			memset(ch, 0, sizeof(ch));
		}
	}sam[maxn];
	int last, m, n;
	int sz[maxn], rs[maxn], h[maxn], b[maxn];
	void append(int w) {
		int p = last, np, q, nq;
		sam[last = np = ++m] = node(sam[p].val + 1);
		rs[np] = 1;
		while (p && sam[p].ch[w] == 0)
			sam[p].ch[w] = np, p = sam[p].par;
		if (p == 0) {
			sam[np].par = 1;
			return;
		}
		q = sam[p].ch[w];
		if (sam[p].val + 1 == sam[q].val) sam[np].par = q;
		else {
			sam[nq = ++m] = sam[q];
			sam[nq].val = sam[p].val + 1;
			sam[q].par = sam[np].par = nq;
			while (p && sam[p].ch[w] == q)
				sam[p].ch[w] = nq, p = sam[p].par;
		}
	}
	void init_sam(char *st) {
		sam[last = m = 1] = node(0);
		n = strlen(st + 1);
		for (int i = 1; i <= n; i++)
			append(st[i] - 'A');
	}
	int cal(char *st) {
		int res = 0, now = 1;
		int m = strlen(st + 1);
		while (now <= m) {
			res++;
			int old_now = now;
			int cur = 1;
			while (now <= m && sam[cur].ch[st[now] - 'A']) cur = sam[cur].ch[st[now] - 'A'], now++;
			if (now == old_now) {
				res = -1;
				break;
			}
		}
		return res;
	}
}A;
char s[N], t[N];
int main()
{
	IO;
	scanf("%s", s + 1);
	A.init_sam(s);
	int k;
	scanf("%d", &k);
	while (k--) {
		scanf("%s", t + 1);
		printf("%d\n", A.cal(t));
	}
	return 0;
}