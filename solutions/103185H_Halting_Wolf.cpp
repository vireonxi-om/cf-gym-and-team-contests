// Problem: Halting Wolf
// URL: https://codeforces.com/gym/103185/problem/H
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
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, val[110][110];
int ed,st;
int num=1,d[N],now[N];
int e[M],pre[M],last[N],f[M];
void insert(int x,int y,int z)
{
    e[++num]=y,f[num]=z,pre[num]=last[x],last[x]=num;
    e[++num]=x,f[num]=0,pre[num]=last[y],last[y]=num;
}
queue<int> q;
bool bfs()
{
    memset(d,-1,sizeof(d));
    d[st]=0;
    q.push(st);
    while(!q.empty())
    {
        int now=q.front();
        for (int i=last[now];i;i=pre[i])
            if(f[i]&&d[e[i]]==-1)
            {
                d[e[i]]=d[now]+1;
                q.push(e[i]);
            }
        q.pop();
    }
    if(d[ed]==-1)return 0;
    return 1;
}
int dfs(int x,int incf)
{
    if(x==ed)return incf;
    int flow=0,w;
    for (int i=now[x];i;i=pre[i])
        if(f[i]&&d[e[i]]==d[x]+1)
        {
            w=dfs(e[i],min(incf-flow,f[i]));
            f[i]-=w,f[i^1]+=w;
            flow+=w;
            if (f[i]) now[x]=i;
            if(flow==incf) return incf;
        }
    if(!flow) d[x]=-1;
    return flow;
}
int dinic()
{
    int maxflow=0;
    while(bfs())
    {
        for (int i=st;i<=ed;i++)
            now[i]=last[i];
        maxflow+=dfs(st,1e9);
    }
    return maxflow;
}

int main() {
    scanf("%d", &n);
    char ss[10];
    int m;
    repn(i, 1, n) {
        scanf("%s", ss);
        if (ss[0] == '*') {
            scanf("%d", &m);
            if (m == 1) m = n + 1;
            val[i][m] = 110000;
        }
        else {
            int k = atoi(ss);
            repn(j, 1, k) {
                scanf("%d", &m);
                if (m == 1) m = n + 1;
                val[i][m] ++;
            }
        }
    }
    repn(i, 1, n + 1) {
        repn(j, 1, n + 1) {
            if (!val[i][j]) continue;
            insert(i, j, val[i][j]);
        }
    }
    ed = n + 1; st = 1;
    int ans = dinic();
    if (ans > 10010) printf("*\n");
    else printf("%d\n", ans + 1);
    return 0;
}

