// Problem: Hardcore Hangman
// URL: https://codeforces.com/gym/104059/problem/H
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
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int p[7][N];
string s[7];
string tot= "abcdefghijklmnopqrstuvwxyz";
int ans[N], res[N];

int main() {
    IO;
    int n = 0;
    s[1] = tot.substr(0, 18);
    s[2] = tot.substr(9, 17);
    s[3] = tot.substr(0, 6) + tot.substr(9, 6) + tot.substr(18, 6);
    s[4] = tot.substr(3, 6) + tot.substr(12, 6) + tot.substr(21, 5);
    s[5] = tot.substr(0, 2) + tot.substr(3, 2) + tot.substr(6, 2) + tot.substr(9, 2) 
    + tot.substr(12, 2) + tot.substr(15, 2) + tot.substr(18, 2) + tot.substr(21, 2) + tot.substr(24, 1);
    s[6] = tot.substr(1, 2) + tot.substr(4, 2) + tot.substr(7, 2) + tot.substr(10, 2) 
    + tot.substr(13, 2) + tot.substr(16, 2) + tot.substr(19, 2) + tot.substr(22, 2) + tot.substr(25, 1);
    repn(i, 1, 6) {
        cout << "? " + s[i] << endl;
        fflush(stdout);
        int num, pos;
        cin >> num;
        repn(j, 1, num){
            cin >> pos;
            n = max(n, pos);
            p[i][pos] = 1;
        }
    }
    rep(i, 0, 26) {
        repn(j, 1, n) res[j] = 1;
        repn(j, 1, 3){
            int t1 = 2 * j - 1, t2 = 2 * j; 
            bool y1 = false, y2 = false;
            for(auto x: s[t1]) if (x - 'a' == i) y1 = true;
            for(auto x: s[t2]) if (x - 'a' == i) y2 = true;
            if (y1 && y2) {
                repn(k, 1, n) {
                    if (p[t1][k] && p[t2][k]) continue;
                    else res[k] = 0;
                }
            }
            else if (y1) {
                repn(k, 1, n) {
                    if (! p[t2][k]) continue;
                    else res[k] = 0;
                }
            }
            else if (y2) {
                repn(k, 1, n) {
                    if (! p[t1][k]) continue;
                    else res[k] = 0;
                }
            }
        }
        repn(k, 1, n) if (res[k]) ans[k] = i;
    }
    cout << "! ";
    repn(i, 1, n) {
        cout << (char) ('a' + ans[i]);
    }
    cout << endl;
    fflush(stdout);
    return 0;
}



