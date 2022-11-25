// Problem: Needle
// URL: https://codeforces.com/gym/102920/problem/H
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

#define complex my
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 810000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

const double PI = acos(-1.0);
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0){r = _r; i = _i;}
    complex operator +(const complex &b){return complex(r+b.r,i+b.i);}
    complex operator -(const complex &b){return complex(r-b.r,i-b.i);}
    complex operator *(const complex &b){return complex(r*b.r-i*b.i,r*b.i+i*b.r);}
}x1[N],x2[N],w1[N],w2[N];
void change(complex y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft_init()
{
	for (int h=2;h<=(1<<18);h<<=1)
		for (int d=0;d<h/2;d++)
			w1[h+d]=complex(cos(2*d*PI/h),sin(2*d*PI/h)),w2[h+d]=complex(cos(-2*d*PI/h),sin(-2*d*PI/h));
}
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
        for(int j=0;j<len;j+=h)
            for(int k=j,d=0;k<j+h/2;k++,d++)
            {
				complex w;
				if (on==1) w=w1[h+d];
				else w=w2[h+d];
                complex u=y[k], t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;               
            }
    if(on==-1)
        for(int i=0;i<len;i++)
            y[i].r/=len;
}
int n1, n2, n3;
int a[N];
int main()
{
	IO;
	fft_init();
	cin >> n1;
	repn(i, 1, n1) {
		int x;
		cin >> x;
		x += 30000;
		x1[x] = complex(1.0, 0.0);
	}
	cin >> n2;
	repn(i, 1, n2) cin >> a[i];
	cin >> n3;
	repn(i, 1, n3) {
		int x;
		cin >> x;
		x += 30000;
		x2[x] = complex(1.0, 0.0);
	}
	int len = 1;
	while (len <= 120000) len *= 2;
	fft(x1, len, 1);
	fft(x2, len, 1);
	rep(i, 0, len) x1[i] = x1[i] * x2[i];
	fft(x1, len, -1);
	LL ans = 0;
	repn(i, 1, n2) ans += (LL)(x1[2 * a[i] + 60000].r + 0.5);
	cout << ans << endl;
	return 0;
}