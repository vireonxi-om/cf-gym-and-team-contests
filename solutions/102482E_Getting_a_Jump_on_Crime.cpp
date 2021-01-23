// Problem: Getting a Jump on Crime
// URL: https://codeforces.com/gym/102482/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 210000;
const int M = 210000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int dx, dy, w, lx, ly;
int a[25][25], flag[25][25];
vector<PII> b[25][25];
double g = 9.80665, v;
vector<pair<double, double>> tmp;

int dcmp(double a) {
	if (a > eps) return 1;
	else if (a < -eps) return -1;
	else return 0;
}

double dist(double i1, double j1, double i2, double j2) {
	return sqrt((i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2));
}

int findmin4(int i, int j) {
	int res = a[i/2][j/2];
	res = max(res, a[i/2 + 1][j/2]);
	res = max(res, a[i/2][j/2 + 1]);
	res = max(res, a[i/2 + 1][j/2 + 1]);
	return res;
}
int findmin2(int i, int j) {
	if (i % 2) {
		return max(a[(i + 1)/2][j/2], a[(i + 1)/2][j/2 + 1]);
	}
	else {
		return max(a[i/2][(j + 1)/2], a[i/2 + 1][(j + 1)/2]);
	}
}


int work(int ti, int tj, int ki, int kj) {
	int t1 = 2 * (ti - 1) + 1, t2 = 2 * (tj - 1) + 1;
	int k1 = 2 * (ki - 1) + 1, k2 = 2 * (kj - 1) + 1;
	int s1 = t1, s2 = t2; 
	
	double d = dist(t1, t2, k1, k2) * w / 2;
	double h = a[ki][kj] - a[ti][tj];
	double val = (h * g - v * v) * (h * g - v * v) - g * g * (h * h + d * d);
	if (dcmp(val) < 0) return 0;
	double t = (v * v - h * g + sqrt(val)) / (g * g / 2); 
	if (dcmp(t) <= 0) return 0;
	t = sqrt(t);
	double vd = d / t;
	double vh = v * v - vd * vd;
	if (dcmp(vh) < 0) return 0;
	vh = sqrt(vh);
	
	tmp.clear();
	if (k1 < t1) {
		swap(k1, t1); swap(k2, t2);
	}
	for (int i = t1 + 1; i < k1; i += 2) {
		int val1 = (i - t1) * (k2 - t2), val2 = (k1 - t1); 
		double cur = t2 + (double) val1 / val2;
		int minh = 1e4;
		if ((val1 % val2 == 0) && ((val1 / val2) % 2)) {
			minh = findmin4(i, t2 + val1 / val2);
		}
		else {
			int num1 = ceil(cur), num2 = floor(cur);
			if (num1 % 2) minh = findmin2(i, num1);
			else minh = findmin2(i, num2);
		}
		tmp.pb(mp(dist(i, cur, s1, s2) * w / 2, minh)); 
	}
	if (k2 < t2) {
		swap(k1, t1); swap(k2, t2);
	}
	for (int j = t2 + 1; j < k2; j += 2) {
		int val1 = (j - t2) * (k1 - t1), val2 = (k2 - t2);
		double cur = t1 + (double) val1 / val2;
		int minh = 1e4;
		if ((val1 % val2 == 0) && ((val1 / val2) % 2)) {
			minh = findmin4(t1 + val1 / val2, j);
		}
		else {
			int num1 = ceil(cur), num2 = floor(cur);
			if (num1 % 2) minh = findmin2(num1, j);
			else minh = findmin2(num2, j);
		}
		tmp.pb(mp(dist(cur, j, s1, s2) * w / 2, minh)); 
	}
	
	for (auto pr : tmp) {
		double cur_t = pr.fi / vd;
		double cur_h = vh * cur_t - g * cur_t * cur_t / 2 + a[ti][tj];
		if (dcmp(cur_h - pr.se) <= 0) return 0;
	}
	return 1;
}

queue<PII> q;
int main() {
	IO;
	cin >> dx >> dy >> w >> v >> lx >> ly;
	repn(i, 1, dy) {
		repn(j, 1, dx) {
			cin >> a[i][j];
		}
	}
	repn(ti, 1, dy) {
		repn(tj, 1, dx) {
			repn(ki, 1, dy) {
				repn(kj, 1, dx) {
					if (ti == ki && tj == kj) continue;
					int val = work(ti, tj, ki, kj); 
					//cout << ti << " " << tj << " " << ki << " " << kj << ": " << val << "\n";
					if (val) {
						b[ti][tj].pb(mp(ki, kj));
					}
				}
			}
		}
	}
	flag[ly][lx] = 1;
	q.push(mp(ly, lx));
	while (!q.empty()) {
		PII cur = q.front();
		//vcout << cur.fi << " " << cur.se << " " << flag[cur.fi][cur.se] << "\n";
		q.pop();
		for (auto pr: b[cur.fi][cur.se]) {
			if (flag[pr.fi][pr.se]) continue;
			flag[pr.fi][pr.se] = flag[cur.fi][cur.se] + 1;
			q.push(pr);
		}
	}
	repn(i, 1, dy) {
		repn(j, 1, dx) {
			if (flag[i][j] == 0) cout << "X ";
			else cout << flag[i][j] - 1 << " ";
		}
		cout << "\n";
	}
}

