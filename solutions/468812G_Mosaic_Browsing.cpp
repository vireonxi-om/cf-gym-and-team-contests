// Problem: Mosaic Browsing
// URL: https://codeforces.com/gym/468812/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

#define complex my
const double PI = acos(-1.0);
struct complex {
    double r, i;
    complex(double _r = 0.0, double _i = 0.0) {r = _r; i =_i;}
    complex operator + (const complex &b){return complex(r + b.r, i + b.i);}
    complex operator - (const complex &b){return complex(r - b.r, i - b.i);}
    complex operator * (const complex &b){return complex(r * b.r - i * b.i, r * b.i + i * b.r);}
    complex conj() {return complex(r, -i);}
};
const int MAXN = 2048;
complex W[2][MAXN * 2];
void init() {
	for (int h = 2; h <= MAXN; h <<= 1)
		for (int d = 0; d < h / 2; d++) {
			W[0][h + d] = complex(cos(2 * d * PI / h), sin(2 * d * PI / h));
			W[1][h + d] = complex(cos(-2 * d * PI / h), sin(-2 * d * PI / h));
		}
}
void change(complex y[], int len) {
    int i, j, k;
    for(i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j) swap(y[i], y[j]);
        k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if (j < k) j += k;
    }
}
void fft(complex y[], int len, int type) {
    change(y, len);
    for(int h = 2; h <= len; h <<= 1)
        for(int j = 0; j < len; j += h)
            for(int k = j, d = 0; k < j + h / 2; k++, d++) {
				complex w;
				if (type == 1) w = W[0][h + d];
				else w = W[1][h + d];
                complex u = y[k], t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;               
            }
    if(type == -1) rep(i, 0, len) y[i].r /= len, y[i].i /= len;
}

int n, m, r, c;
int a[N][N], b[N][N];
LL f[N][N];
int g[N][N], h[N][N];
complex f1[N][N], f2[N][N], t1[N][N], t2[N][N];
void work() {
	int len = 1024;
	memset(f1, 0, sizeof(f1)), memset(f2, 0, sizeof(f2));
	rep(i, 0, len) rep(j, 0, len) f1[i][j] = complex(g[i][j], 0);
	rep(i, 0, len) rep(j, 0, len) f2[i][j] = complex(h[i][j], 0);
	
//	rep(i, 0, n) rep(j, 0, m) {
//		repn(x, 0, i) repn(y, 0, j) {
//			f[i][j] += g[i - x][j - y] * h[x][y];
//		}
//	}
//			
//	return;
	
	// row dft
	rep(i, 0, len) fft(f1[i], len, 1), fft(f2[i], len, 1);
	// col dft
	rep(i, 0, len) rep(j, 0, len) t1[i][j] = f1[j][i], t2[i][j] = f2[j][i];
	rep(i, 0, len) fft(t1[i], len, 1), fft(t2[i], len, 1);

	rep(i, 0, len) {
		rep(j, 0, len) t1[i][j] = t1[i][j] * t2[i][j];
		// row idft
		fft(t1[i], len, -1);
	}
	// col idft
	rep(i, 0, len) rep(j, 0, len) f1[i][j] = t1[j][i];
	rep(i, 0, len) fft(f1[i], len, -1);
	rep(i, 0, n) rep(j, 0, m) {
		LL v;
		if (f1[i][j].r > 0) v = (LL)(f1[i][j].r + 0.5);
		else v = (LL)(f1[i][j].r - 0.5);
		f[i][j] += v;
	}
}
vector<PII> ans;
int main() {
	IO;
	init();
	cin >> r >> c;
	per(i, 0, r) per(j, 0, c) cin >> b[i][j];
	cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
	
	// a^2 b
	memset(g, 0, sizeof(g)), memset(h, 0, sizeof(h));
	rep(i, 0, n) rep(j, 0, m) g[i][j] = a[i][j] * a[i][j];
	rep(i, 0, r) rep(j, 0, c) h[i][j] = b[i][j];
	work();
	// -2ab^2
	memset(g, 0, sizeof(g)), memset(h, 0, sizeof(h));
	rep(i, 0, n) rep(j, 0, m) g[i][j] = -2 * a[i][j];
	rep(i, 0, r) rep(j, 0, c) h[i][j] = b[i][j] * b[i][j];
	work();
	// b^3
	memset(g, 0, sizeof(g)), memset(h, 0, sizeof(h));
	rep(i, 0, n) rep(j, 0, m) g[i][j] = 1;
	rep(i, 0, r) rep(j, 0, c) h[i][j] = b[i][j] * b[i][j] * b[i][j];
	work();
//	rep(i, 0, n) rep(j, 0, m) {
//		rep(x, 0, r) rep(y, 0, c) f[i][j] += (a[i - x][j - y] - b[x][y]) * (a[i - x][j - y] - b[x][y]) * b[x][y];
//	}
	rep(i, r - 1, n) rep(j, c - 1, m) if (f[i][j] == 0) {
		ans.pb(mp(i + 2 - r, j + 2 - c));
	}
	cout << ans.size() << "\n";
	for (auto p: ans) cout << p.fi << " " << p.se << "\n";
	return 0;
}