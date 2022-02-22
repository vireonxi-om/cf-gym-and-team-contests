// Problem: Find the Length
// URL: https://codeforces.com/gym/100917/problem/F
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

const int N = 303;
const int M = 650;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n;
LL e[N][N], d[12][N][N];
LL ans[N];

void merge(int l, int r, int now, int fa){
    repn(i, 1, n){
        repn(j, 1, n) d[now][i][j] = d[fa][i][j];
    }
    repn(k, l, r){
        repn(i, 1, n){
            repn(j, 1, n) d[now][i][j] = min(d[now][i][j], d[now][i][k] + d[now][k][j]);
        }
    }
}

void pd(int l, int r, int depth){
    if (l == r) {
    	/*
        printf("%d\n", l);
        repn(i, 1, n){
            repn(j, 1, n){
                printf("%lld ", d[k][i][j]);
            }
            printf("\n");
        }
        */
        repn(i, 1, n){
            repn(j, 1, n) if (i != l && j != l && i != j) ans[l] = min(ans[l], d[depth][i][j] + e[i][l] + e[l][j]);
        }
        return;
    }
    int mid = (l + r) / 2;
    merge(l, mid, depth + 1, depth); pd(mid+1, r, depth + 1);
    merge(mid+1, r, depth + 1, depth); pd(l, mid, depth + 1);
}


int main() {
    IO;
    scanf("%d", &n);
    repn(i, 1, n) ans[i] = INF;
    repn(i, 1, n) {
        repn(j, 1, n) {
            scanf("%lld", &e[i][j]);
            if (e[i][j] == -1) e[i][j] = INF;
            d[1][i][j] = e[i][j];
            //if (i == j) d[1][i][j] = 0;
            //else d[1][i][j] = INF;
        }
    }

    pd(1, n, 1);
    repn(i, 1, n) {
        if (ans[i] < INF) printf("%lld\n", ans[i]);
        else printf("-1\n");
    }

    return 0;
}

