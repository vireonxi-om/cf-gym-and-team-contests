// Problem: Autonomous Vehicle
// URL: https://codeforces.com/gym/102920/problem/A
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

// 0 - left, 1 - right, 2 - up, 3 - down
// 0 - endpoint, 1 - crosspoint
map<pair<pair<int, int>, int>, pair<int, int> > S;
map<pair<int, int>, int> SS;
map<pair<int, int>, int> TS;
int n, t, cnt;
struct line {
	int x1, y1, x2, y2, op;
	void read() {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) op = 1;
		else op = 0;
	}
}a[N];
LL dis[M];
map<int, set<int> > row, col;
int nxtdir(int x) {
	if (x == 0) return 3;
	if (x == 1) return 2;
	if (x == 2) return 0;
	return 1;
}
void work() {
	int cur = 0;
	int x = a[1].x1, y = a[1].y1, dir;
	if (a[1].op == 0) {
		if (a[1].x1 < a[1].x2) dir = 1;
		else dir = 0;
	}
	else {
		if (a[1].y1 < a[1].y2) dir = 2;
		else dir = 3;
	}
	int flag = 0;
	int idx = S[mp(mp(x, y), dir)].fi;
	dis[idx] = 0;
	while (1) {
		int nx, ny, delta;
		int odir = dir;
		if (dir == 0) {
			auto it = row[y].lower_bound(x);
			if (TS[mp(x, y)] == dir || it == row[y].begin())  nx = x, ny = y, dir ^= 1;
			else {
				it--, nx = *it, ny = y;
				if (SS[mp(nx, ny)] == 1) dir = nxtdir(dir);
			}
		}
		else if (dir == 1) {
			auto it = row[y].upper_bound(x);
			if (TS[mp(x, y)] == dir || it == row[y].end())  nx = x, ny = y, dir ^= 1;
			else {
				nx = *it, ny = y;
				if (SS[mp(nx, ny)] == 1) dir = nxtdir(dir);
			}
		}
		else if (dir == 3) {
			auto it = col[x].lower_bound(y);
			if (TS[mp(x, y)] == dir || it == col[x].begin()) nx = x, ny = y, dir ^= 1;
			else {
				it--, nx = x, ny = *it;
				if (SS[mp(nx, ny)] == 1) dir = nxtdir(dir);
			}
		}
		else {
			auto it = col[x].upper_bound(y);
			if (TS[mp(x, y)] == dir || it == col[x].end()) nx = x, ny = y, dir ^= 1;
			else {
				nx = x, ny = *it;
				if (SS[mp(nx, ny)] == 1) dir = nxtdir(dir);
			}
		}
		delta = abs(nx - x) + abs(ny - y);
		if (cur + delta >= t) {
			int left = t - cur, ansx, ansy;
			if (odir == 0) ansx = x - left, ansy = y;
			else if (odir == 1) ansx = x + left, ansy = y;
			else if (odir == 2) ansx = x, ansy = y + left;
			else ansx = x, ansy = y - left;
			cout << ansx << " " << ansy << endl;
			exit(0);
		}
		cur += delta;
		if (flag == 0) {
			int idx = S[mp(mp(nx, ny), dir)].fi;
			if (dis[idx] != -1) {
				int len = cur - dis[idx];
				t -= (t - cur) / len * len;
				flag = 1;
			}
			else dis[idx] = cur;
		}
		x = nx, y = ny;
	}
}
int main()
{
	IO;
	cin >> n >> t;
	repn(i, 1, n) {
		a[i].read();
		col[a[i].x1].insert(a[i].y1);
		col[a[i].x2].insert(a[i].y2);
		row[a[i].y1].insert(a[i].x1);
		row[a[i].y2].insert(a[i].x2);
		SS[mp(a[i].x1, a[i].y1)] = 0;
		SS[mp(a[i].x2, a[i].y2)] = 0;
		if (a[i].x1 == a[i].x2) {
			S[mp(mp(a[i].x1, a[i].y1), 3)] = mp(++cnt, 0);
			S[mp(mp(a[i].x1, a[i].y2), 2)] = mp(++cnt, 0);
			S[mp(mp(a[i].x1, a[i].y1), 2)] = mp(++cnt, 0);
			S[mp(mp(a[i].x1, a[i].y2), 3)] = mp(++cnt, 0);
			TS[mp(a[i].x1, min(a[i].y1, a[i].y2))] = 3;
			TS[mp(a[i].x1, max(a[i].y1, a[i].y2))] = 2;
		}
		else {
			S[mp(mp(a[i].x1, a[i].y1), 1)] = mp(++cnt, 0);
			S[mp(mp(a[i].x2, a[i].y1), 0)] = mp(++cnt, 0);
			S[mp(mp(a[i].x1, a[i].y1), 0)] = mp(++cnt, 0);
			S[mp(mp(a[i].x2, a[i].y1), 1)] = mp(++cnt, 0);
			TS[mp(min(a[i].x1, a[i].x2), a[i].y1)] = 0;
			TS[mp(max(a[i].x1, a[i].x2), a[i].y1)] = 1;
		}
	}
	repn(i, 1, n) {
		repn(j, i + 1, n) {
			if (a[i].op ^ a[j].op) {
				int cx, cy;
				if (a[i].op == 0) {
					// y1 == y2
					if (max(a[i].x1, a[i].x2) <= a[j].x1) continue;
					if (min(a[i].x1, a[i].x2) >= a[j].x1) continue;
					if (max(a[j].y1, a[j].y2) <= a[i].y1) continue;
					if (min(a[j].y1, a[j].y2) >= a[i].y1) continue;
					cx = a[j].x1, cy = a[i].y1;
				}
				else {
					// x1 == x2
					if (max(a[j].x1, a[j].x2) <= a[i].x1) continue;
					if (min(a[j].x1, a[j].x2) >= a[i].x1) continue;
					if (max(a[i].y1, a[i].y2) <= a[j].y1) continue;
					if (min(a[i].y1, a[i].y2) >= a[j].y1) continue;
					cx = a[i].x1, cy = a[j].y1;
				}
				col[cx].insert(cy);
				row[cy].insert(cx);
				SS[mp(cx, cy)] = 1;
				TS[mp(cx, cy)] = -1;
				S[mp(mp(cx, cy), 0)] = mp(++cnt, 1);
				S[mp(mp(cx, cy), 1)] = mp(++cnt, 1);
				S[mp(mp(cx, cy), 2)] = mp(++cnt, 1);
				S[mp(mp(cx, cy), 3)] = mp(++cnt, 1);
			}
		}
	}
	memset(dis, -1, sizeof(dis));
	work();	
	return 0;
}