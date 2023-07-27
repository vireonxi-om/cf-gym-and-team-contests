// Problem: Jumping Cat
// URL: https://codeforces.com/gym/102896/problem/J
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 510000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-15;

int n, L;
int d[60], h[60];
double dp[110];

double len(double x, double y) {
    return sqrt(x * x + y * y);
}

double wid(double he, double d1, double d2) {
    if (he > L) return -1;
    double w = sqrt(L * L - he * he);
    if (d1 - w > eps) return -1;
    if (w - d2 > eps) w = d2;
    return w;
}

bool checkup(int s, int t, double he, double w) {
    rep(tar, s + 1, t) {
        double dd = d[t] - d[tar];
        if (h[tar] - h[s] - (w - dd) * he / w > eps) return false;
    }
    return true;
}
bool checkdown(int s, int t, double he, double w) {
    rep(tar, s + 1, t) {
        double dd = d[tar + 1] - d[s + 1];
        //printf("h: %.10f\n", (w - dd) * he / w);
        if (h[tar] - h[t] - (w - dd) * he / w > eps) return false;
    }
    return true;
}

double up(int i, int j) {
    int s = i / 2, t = j / 2;
    double he = h[t] - h[s], w = wid(he, d[t] - d[s + 1], d[t] - d[s]);
    if (w < - 0.5) return (double)inf;
    if (checkup(s, t, he, w)) return len(he, w) + d[t] - d[s] - w;
    else return (double)inf;
}
double down(int i, int j) {
    int s = i / 2, t = j / 2;
    double he = h[s] - h[t], w = wid(he, d[t] - d[s + 1], d[t + 1] - d[s + 1]);
    if (w < - 0.5) return (double)inf;
    if (checkdown(s, t, he, w)) return len(he, w) + d[t + 1] - d[s + 1] - w;
    else return (double)inf;
}
double tri(int i, int j, int k) {
    int s = i / 2, m = j / 2, t = k / 2;
    double h1 = h[s] - h[m], h2 = h[t] - h[m];
    double w1 = wid(h1, d[m] - d[s + 1], d[m + 1] - d[s + 1]);
    double w2 = wid(h2, d[t] - d[m + 1], d[t] - d[m]);
    //printf("0\n");
    if (w1 < - 0.5 || w2 < - 0.5) return (double)inf;
    //printf("1\n");
    if (w1 + w2 - d[t] + d[s + 1] < eps) {
        if (!checkdown(s, m, h1, w1)) return (double)inf;
        //printf("2\n");
        if (!checkup(m, t, h2, w2)) return (double)inf;
        //printf("3\n");
        return len(h1, w1) + len(h2, w2) + d[t] - d[s + 1] - w1 - w2;
    }
    else {
        double l = d[t] - w2, r = d[s + 1] + w1;
        //printf("l: %.10f  r: %.10f\n", l, r);
        repn(ti, 1, 50) {
            double m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
            if (!checkup(m, t, h2, d[t] - m2)) {r = m2; continue; }
            if (!checkdown(s, m, h1, m1 - d[s + 1])) {l = m1; continue; }
            double now1 = len(h1, m1 - d[s + 1]) + len(h2, d[t] - m1);
            double now2 = len(h1, m2 - d[s + 1]) + len(h2, d[t] - m2);
            if (now1 - now2 > eps)  {l = m1; continue;}
            else  {r = m2; continue;}
        }
        //printf("%.10f\n", l);
        if (!checkup(m, t, h2, d[t] - l)) return (double)inf;
        //printf("3\n");
        if (!checkdown(s, m, h1, l - d[s + 1])) return (double)inf;
        //printf("4\n");
        return len(h1, l - d[s + 1]) + len(h2, d[t] - l);
    }
}

int main() {
    scanf("%d%d", &n, &L);
    repn(i, 1, n) scanf("%d", &d[i]);
    rep(i, 0, n) scanf("%d", &h[i]);
    rep(i, 1, 2 * n) dp[i] = inf;
    rep(i, 0, 2 * n) {
        if (i % 2) {
            for (int j = i + 2; j < 2 * n; j += 2) {
                if (h[j / 2] > h[i / 2]) continue;
                dp[j] = min(dp[j], dp[i] + down(i, j));
                //if (h[j / 2] == h[i / 2]) continue;
                for (int k = j + 1; k < 2 * n; k += 2) {
                    if (h[k / 2] < h[j / 2]) continue;
                    dp[k] = min(dp[k], dp[i] + tri(i, j - 1, k));
                }
            }
        }
        else {
            dp[i + 1] = min(dp[i + 1], dp[i] + d[i / 2 + 1] - d[i / 2]);
            for (int j = i + 2; j < 2 * n; j += 2) {
                if (h[j / 2] < h[i / 2]) continue;
                dp[j] = min(dp[j], dp[i] + up(i, j));
            }
        }
    }
    if (dp[2 * n - 1] > 1e8) printf("-1\n");
    else printf("%.13f\n", dp[2 * n - 1]);
    return 0;
}