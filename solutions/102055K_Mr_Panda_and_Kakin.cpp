// Problem: Mr. Panda and Kakin
// URL: https://codeforces.com/gym/102055/problem/K
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

int T, cas;
LL n, c;
LL a[N];
int num;
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
    int s=5,t=0,i;
    LL a,p,k=n-1;
    LL b[7]={2,325,9375,28178,450775,9780504,1795265022};
    while (k%2==0) k/=2,t++;
   	rep(i, 0, 7) {
        a = b[i];
        p = a = qsm(a,k,n);
        for (int i=1;i<=t;i++){
            a=mul(a,a,n);
            if (a==1&&p!=1&&p!=n-1) return 0;
            p=a;
        }
        if (a!=1) return 0;
    }
    return 1;
}
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}
LL Pollard_Rho(LL n){
    LL k,x,y,c,d,i=1;
    while (1){
        c=random(n-1);
        k=2;y=x=random(n);
        i=1;
        while (1){
            y=(mul(y,y,n)+c)%n;
            d=gcd(abs(x-y),n);
            if (i==k) x=y,k<<=1;
            i++;
            if (d!=1) break;
        }
        if (d!=n) return d;
    }
}
void work(LL n){
    if (isPrime(n)){
        a[++num]=n;
        return;
    }
    LL p=Pollard_Rho(n);
    LL q=n/p;
    work(p);work(q);
}
LL l;
LL extended_gcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        LL r=extended_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
LL inv(LL a,LL n)
{
	LL xx,yy,d=extended_gcd(a,n,xx,yy);
	return (xx%n+n)%n;
}
LL pow_mod(LL a, LL e, LL mod) {
	LL res = 1;
	for (;e; a = mul(a, a, mod), e >>= 1) if (e & 1) res = mul(res, a, mod);
	return res;
}
LL work(LL c, LL n, LL phi) {
	LL k = inv(l, phi);
	return pow_mod(c, k, n);
}
int main()
{
	IO;
	cin >> T;
	l = (1LL << 30) + 3;
	while (T--) {
		cas++;
		cin >> n >> c;
		num = 0;
		//work(n);
		LL p, q;
		LL t = sqrt(n);
		while (1) {
			if (n % t == 0) {
				p = t, q = n / t;
				break;
			}
			t--;
		}
		LL ans;
		if (c % p == 0) ans = mul(p, work(c / p, n / p, q - 1), n);
		else if (c % q == 0) ans = mul(q, work(c / q, n / q, p - 1), n);
		else ans = work(c, n, (p - 1) * (q - 1));
		assert(pow_mod(ans, l, n) == c);
		cout << "Case " << cas << ": " << ans << "\n";
	}
	return 0;
}