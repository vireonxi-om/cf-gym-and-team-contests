// Problem: Know your Aliens
// URL: https://codeforces.com/gym/102428/problem/K
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

const int N = 11000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
char s[N];
struct poly
{
	LL a[N];
	void clear() {
		memset(a, 0, sizeof(a));
	}
	LL & operator [] (int x) {
        return a[x];
    }
	friend poly operator * (poly a, poly b) {
		poly res;
		res.clear();
		int na = 0, nb = 0;
		per(i, 0, N)
			if (a.a[i]) {
				na = i;
				break;
			}
		per(i, 0, N)
			if (b.a[i]) {
				nb = i;
				break;
			}
		repn(i, 0, na)
			for (int j = 0; i + j < N && j <= nb; j++)
				res.a[i + j] = res.a[i + j] + a.a[i] * b.a[j];
		return res;
	}
}f1, f2;
int main()
{
	IO;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f1[0] = 1;
	repn(i, 2, n) {
		if (s[i] != s[i - 1]) {
			f2.clear();
			f2[0] = -(2 * i - 1);
			f2[1] = 1;
			f1 = f1 * f2;
		}
	}
	f2.clear(), f2[0] = -1;
	if (s[1] == 'A' && f1[0] > 0) f1 = f1 * f2;
	else if (s[1] == 'H' && f1[0] < 0) f1 = f1 * f2;
	int num;
	per(i, 0, N) if (f1[i] != 0) {
		num = i;
		break;
	}
	cout << num << "\n";
	pern(i, 0, num) {
		cout << f1[i];
		if (i != 0) cout << " ";
		else cout << "\n";
	}
	return 0;
}