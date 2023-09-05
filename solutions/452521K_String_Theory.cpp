// Problem: String Theory
// URL: https://codeforces.com/gym/452521/problem/K
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
typedef pair<LL, LL> PLL;
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 2100;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-15;
const double pi = acos(-1.0);


int n, a[110], b[110];

int main() {
	IO;
	cin >> n;
	int sum = 0;
	repn(i, 1, n) {
		cin >> a[i]; 
		sum += a[i];
	}
	pern(i, 1, 100) {
		int cur = (1 + i) * i;
		if (sum < cur) continue;
		if ((sum - cur) % 2) continue;
		if (i == 1 && sum != cur) continue;
		repn(j, 1, n) b[j] = a[j];
		int pos = 1;
		bool can = true;
		pern(j, 1, i) {
			if (pos > n) can = false;
			if (b[pos] < j) can = false;
			if (!can) break;
			b[pos] -= j;
			if (b[pos] == 0) pos ++;
		}
		if (!can) continue;
		int tmp = sum - cur;
		while (tmp) {
			if (pos > n) {
				can = false; break;
			}
			if (tmp >= b[pos]) {
				tmp -= b[pos]; 
				b[pos] = 0; pos ++;
			}
			else {
				b[pos] -= tmp;
				tmp = 0;
			}
		}
		if (!can) continue;
		repn(j, 1, i) {
			if (pos > n) can = false;
			if (b[pos] < j) can = false;
			if (!can) break;
			b[pos] -= j;
			if (b[pos] == 0) pos ++;
		}
		if (can && pos == n + 1) {
			cout << i << "\n"; return 0;
		}
	}
	cout << "no quotation\n";
	return 0;
	
}