// Problem: Geometrical Combinatorics
// URL: https://codeforces.com/gym/102896/problem/G
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
const int M = 1000000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T;
int px[4], py[4];
LL ans;
LL f[N], inv[N], ff[N];
LL C(int n, int m) {
	LL res = (f[n] * inv[m]) % mod;
	res = (res * inv[n - m]) % mod;
	return res;
}

vector<double> tmp;
void work(int y, int x1, int y1, int x2, int y2) {
	if (min(y1, y2) > y) return;
	if (max(y1, y2) < y) return;
	if (y1 == y2) {
		tmp.pb(x1);
		tmp.pb(x2);
	}
	else tmp.pb((double)(y - y1) / (double)(y2 - y1) * (x2 - x1) + x1);
}
int cal(int y, int tp) {
	tmp.clear();
	work(y, px[1], py[1], px[2], py[2]);
	work(y, px[1], py[1], px[3], py[3]);
	work(y, px[2], py[2], px[3], py[3]);
	sort(all(tmp));
	double pos;
	int beg;
	beg = -y;
	if (tp == 0) {
		if (tmp.size() > 0) pos = tmp[0] - eps;
		else return -1;
		if (pos < beg) return -1;
		return min((int)((pos - beg) / 2), y);
	}
	else {
		if (tmp.size() > 0) pos = tmp[tmp.size() - 1] + eps;
		else return -1;
		if (pos < beg) return -1;
		return min((int)((pos - beg) / 2), y);
	}
}
int main()
{
	f[0] = 1;
	rep(i, 1, N)
		f[i] = (f[i - 1] * i) % mod;
	ff[1] = ff[0] = inv[1] = inv[0] = 1;  
	rep(i, 2, N) {
    	inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    	ff[i] = inv[i];
	}
	rep(i, 2, N)
		inv[i] = (inv[i - 1] * inv[i]) % mod;
	IO;
	cin >> T;
	while (T--) {
		cin >> px[1] >> py[1] >> px[2] >> py[2] >> px[3] >> py[3];
		ans = 0;
		LL cur = 0;
		int pos = -1;
		repn(i, 0, M) {
			int pl = cal(i, 0);
			if (pos != -1) {
				cur = cur * 2 + mod - C(i - 1, pos);
				cur %= mod;
			}
			while (pos < pl) pos++, cur = (cur + C(i, pos)) % mod;
			while (pos > pl) cur = (cur - C(i, pos) + mod) % mod, pos--;
			ans = (ans + mod - cur) % mod;
		}
		cur = 0;
		pos = -1;
		repn(i, 0, M) {
			int pl = cal(i, 1);
			if (pos != -1) {
				cur = cur * 2 + mod - C(i - 1, pos);
				cur %= mod;
			}
			while (pos < pl) pos++, cur = (cur + C(i, pos)) % mod;
			while (pos > pl) cur = (cur - C(i, pos) + mod) % mod, pos--;
			ans = (ans + cur) % mod;
		}
		cout << ans << "\n";
	}	
	return 0;
}