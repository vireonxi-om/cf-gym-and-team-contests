// Problem: Ultra Weak Goldbach's Conjecture
// URL: https://codeforces.com/gym/102055/problem/L
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
LL random(LL x){
    LL t=rand()%10000;
    t=t*10000+rand()%10000;
    t=t*10000+rand()%10000;
    t=t*10000+rand()%10000;
    return t%x;
}
LL mul(LL a,LL b,LL p){
    LL tmp=(a*b-(LL)((long double)a/p*b+1e-8)*p);
    return tmp<0?tmp+p:(tmp>=p?tmp-p:tmp);
}
LL qsm(LL x,LL y,LL mo){
    if (!y) return 1;
    LL t=qsm(x,y/2,mo);
    t=mul(t,t,mo);
    if (y%2) t=mul(t,x,mo);
    return t;
}
bool isPrime(LL n){
    if (n==1) return 0;
    for (LL i = 2; i * i <= n; i++) {
    	if (n % i == 0) return 0;
    }
    return 1;
}
int T, cnt;
LL n;
vector<LL> ans;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		cnt++;
		if (n <= 11) {
			cout << "Case " << cnt << ": IMPOSSIBLE\n";
			continue;
		}
		LL x;
		if (n & 1) x = n - 11;
		else x = n - 10;
		while (1) {
			if (isPrime(x)) break;
			x--;
		}
		ans.clear();
		ans.pb(x);
		n -= x;
		if (n & 1) ans.pb(3),ans.pb(2),ans.pb(2), n -= 7;
		else ans.pb(2),ans.pb(2),ans.pb(2), n -= 6;
		rep(i, 2, n) {
			if (isPrime(i) && isPrime(n - i)) {
				ans.pb(i);
				ans.pb(n - i);
				break;
			}
		}
		cout << "Case " << cnt << ": ";
		rep(i, 0, 6) {
			cout << " " << ans[i];
		}
		cout << "\n";
	}
	return 0;
}