// Problem: Jumping Grasshoper
// URL: https://codeforces.com/gym/102428/problem/J
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int a[N];
int mx[M];
void update(int k) {
	mx[k] = max(mx[LC], mx[RC]);
}
void change(int k, int l, int r, int a, int b) {
	if (l == r) {
		mx[k] = b;
		return;
	}
	int mid = (l + r) / 2;
	if (a <= mid) change(LC, l, mid, a, b);
	else change(RC, mid + 1, r, a, b);
	update(k);
}
int ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return mx[k];
	int mid = (l + r) / 2;
	if (b <= mid) return ask(LC, l, mid, a, b);
	else if (a > mid) return ask(RC, mid + 1, r, a, b);
	else return max(ask(LC, l, mid, a, mid), ask(RC, mid + 1, r, mid + 1, b));
}
int askl(int k, int l, int r, int a) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (mx[LC] >= a) return askl(LC, l, mid, a);
	else return askl(RC, mid + 1, r, a);
}
int askr(int k, int l, int r, int a) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (mx[RC] >= a) return askr(RC, mid + 1, r, a);
	else return askr(LC, l, mid, a);
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> a[i];
		change(1, 1, n, i, a[i]);
	}
	while (m--) {
		string s;
		cin >> s;
		if (s == "L") {
			int x;
			cin >> x;
			int pl = ask(1, 1, n, 1, x);
			int pr = ask(1, 1, n, x, n);
			if (pl == a[x]) cout << x << "\n";
			else if (pr == a[x]) cout << askr(1, 1, n, a[x] + 1) << "\n";
			else {
				if (pl < pr) cout << askl(1, 1, n, pl + 1) << "\n";
				else cout <<  askr(1, 1, n, pr + 1) << "\n";
			}
		}
		else if (s == "R") {
			int x;
			cin >> x;
			int pl = ask(1, 1, n, 1, x);
			int pr = ask(1, 1, n, x, n);
			if (pr == a[x]) cout << x << "\n";
			else if (pl == a[x]) cout << askl(1, 1, n, a[x] + 1) << "\n";
			else {
				if (pl < pr) cout << askl(1, 1, n, pl + 1) << "\n";
				else cout <<  askr(1, 1, n, pr + 1) << "\n";
			}
		}
		else {
			int x, y;
			cin >> x >> y;
			change(1, 1, n, x, y);
			a[x] = y;
		}
	}
	return 0;
}