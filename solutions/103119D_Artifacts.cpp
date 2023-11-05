// Problem: Artifacts
// URL: https://codeforces.com/gym/103119/problem/D
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

double atk, atk_rate, crit_rate = 5, crit_dmg_rate = 50;
void work() {
	string name = "";
	char x = getchar();
	while (x < 'A' || x > 'Z') x = getchar();
	while (x != '+') {
		name += x;
		x = getchar();
	}
	double num = 0;
	scanf("%lf", &num);
	if (name == "ATK") atk += num;
	else if (name == "ATK Rate") atk_rate += num;
	else if (name == "Crit Rate") crit_rate += num;
	else if (name == "Crit DMG Rate") crit_dmg_rate += num;
}
	
int main()
{
	IO;
	rep(i, 0, 25) {
		work();
	}
	crit_rate = min(crit_rate, 100.0);
	double ans = 1500.0 * (1 + atk_rate / 100.0) + atk;
	ans = ans * (1 - crit_rate / 100.0) + ans * (1 + crit_dmg_rate / 100.0) * (crit_rate / 100.0);
	printf("%.20f\n", ans);
	return 0;
}