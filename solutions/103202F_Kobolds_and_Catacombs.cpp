// Problem: Kobolds and Catacombs
// URL: https://codeforces.com/gym/103202/problem/F
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

int n, b[N], pos[N], npos[N];
PII a[N];
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> b[i];
		a[i] = mp(b[i], i);
	}
	sort(a + 1, a + 1 + n);
	repn(i, 1, n) pos[i] = a[i].se, npos[a[i].se] = i;
	int num = 0, tail = 1;
	repn(i, 1, n) {
		tail = max(tail, npos[i]);
		tail = max(tail, pos[i]);
		if (i == tail) {
			num++;
			tail = i + 1;
		}
	}
	cout << num << endl;
	return 0;
}