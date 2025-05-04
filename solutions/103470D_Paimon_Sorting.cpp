// Problem: Paimon Sorting
// URL: https://codeforces.com/gym/103470/problem/D
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
const int M = 110000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N], b[N], flag[N], mx[N], c[N];
LL ans[N];
int tst[N];

int lowbit(int x) {
  return x & -x;
}
void add(int x, int k) {
  while (x <= n) {
    c[x] = c[x] + k;
    x = x + lowbit(x);
  }
}

int getsum(int x) { 
  int ans = 0;
  while (x >= 1) {
    ans = ans + c[x];
    x = x - lowbit(x);
  }
  return ans;
}

void test() {
	LL cnt;
	bool yes = true;
	repn(t, 1, n) {
		repn(i, 1, n) tst[i] = b[i];
		cnt = 0;
		repn(i, 1, t) {
			repn(j, 1, t) {
				if (tst[i] < tst[j]) {
					swap(tst[i], tst[j]);
					cnt ++;
				} 
			}
		}
		if (cnt != ans[t]){
			yes = false;
			cout << "Wrong! " << t << " " << cnt; 
		} 
	}
	if (yes) cout << "-\n";
	else cout << "No\n";
}

void solve() {
	cin >> n;
	int m = 0;
	repn(i, 0, n) c[i] = 0;
	repn(i, 1, n) {
		cin >> a[i];
		b[i] = a[i];
		flag[i] = 0;
		if (a[i] > m) {
			flag[i] = 1;
			swap(m, a[i]);
		} 
		mx[i] = m;
	}
	int m1 = 0;
	LL cnt = 0;
	bool st = false;
	repn(i, 2, n) {
		ans[i] = ans[i - 1] + flag[i];
		if (mx[i] > mx[i - 1]) {
			ans[i] += cnt;
			cnt = 0;
			st = false;
		}
		ans[i] += getsum(n) - getsum(a[i]);
		if (m1 < mx[i] && a[i] < mx[i]) ans[i] ++;
		if (a[i] == mx[i]) st = true;
		if (st) cnt ++;
		if (getsum(a[i]) - getsum(a[i] - 1) == 0) add(a[i], 1);
		m1 = max(m1, a[i]);
	}
	
	repn(i, 1, n) {
		cout << ans[i];
		if (i != n) cout << " ";
	}
	cout << "\n";
	
	repn(i, 0, n) c[i] = 0;
	//test();
}



int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}




