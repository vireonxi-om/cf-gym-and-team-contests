// Problem: camelCaseCounting
// URL: https://codeforces.com/gym/103176/problem/C
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
const int M = 11000000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAXN = 1001000;


struct suffix_array
{
    int height[MAXN],rank[MAXN],sa[MAXN],h[MAXN],a[MAXN],b[MAXN],f[MAXN][40];
    int n;
    char st[MAXN];
    template<typename T>
    void radix(int a[],int b[],T s[],int m,int n)
    {	int i;
        for (i=0;i<=m;++i)
            h[i]=0;
        for (i=1;i<=n;++i)
            ++h[s[a[i]]];
        for (i=1;i<=m;++i)
            h[i]+=h[i-1];
        for (i=n;i>0;--i)
            b[h[s[a[i]]]--]=a[i];
    }
    void init_sa()
    {	int i,j;
        for (i=1;i<=n;++i)
            rank[i]=i;
        radix(rank,sa,st,255,n);
        rank[sa[1]]=1;
        for (i=2;i<=n;++i)
            if (st[sa[i]]!=st[sa[i-1]])
                rank[sa[i]]=rank[sa[i-1]]+1;
            else rank[sa[i]]=rank[sa[i-1]];
        for (i=1;i<=n;i*=2)
        {	for (j=1;j<=n;++j)
            {	a[j]=rank[j];
                if (i+j<=n)
                    b[j]=rank[i+j];
                else b[j]=0;
                sa[j]=j;
            }
            radix(sa,rank,b,n,n);
            radix(rank,sa,a,n,n);
            rank[sa[1]]=1;
            for (j=2;j<=n;++j)
                if (a[sa[j]]!=a[sa[j-1]]||b[sa[j]]!=b[sa[j-1]])
                    rank[sa[j]]=rank[sa[j-1]]+1;
                else rank[sa[j]]=rank[sa[j-1]];
            if (rank[sa[n]]==n)
                break ;
        }
    }
    void calc_height()
    {	int i,p=0;
        for (i=1;i<=n;++i)
        {	if (p)
                --p;
            if (rank[i]!=1)
                while (st[i+p]==st[sa[rank[i]-1]+p]&&st[i+p]!='|')
                    ++p;
            height[rank[i]]=p;
        }
    }
    void init_rmq()
    {    int i,j;
        for (i=1;i<=n;++i)
            f[i][0]=height[i];
        for (j=1;(1<<j)<=n;++j)
            for (i=1;i+j-1<=n;++i)
                f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
    int rmq(int l,int r)
    {
        int k=0;
        if (l>r)
            swap(l,r);
        while ((1<<(k+1))<=r-l+1)
            ++k;
        return min(f[l][k],f[r-(1<<k)+1][k]);
    }
    int lcp(int l,int r)
    {
        int a,b;
        a=rank[l],b=rank[r];
        if (a>b)
            swap(a,b);
        return rmq(a+1,b);
    }
} A;

int main(){
    scanf("%s", A.st + 1);
    A.n = strlen(A.st + 1);
    A.init_sa();
    A.calc_height();
    int tot = A.n;
    LL ans = 0;
    repn(i, 1, tot) {
        if (A.st[i] - 'a' < 0) continue;
        ans += tot + 1 - i - A.height[A.rank[i]];
    }
    printf("%lld\n", ans);
    return 0;
}
