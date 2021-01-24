// Problem: Chaotic Construction
// URL: https://codeforces.com/gym/104059/problem/C
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
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;

int cnt[N], v[N];

int lowbit(int x) { 
    return x & -x; 
}
void add(int x, int y) { 
    for (int i = x; i < N; i += lowbit(i)) v[i] += y; 
}
int get(int x) { 
    int res = 0; 
    for (int i = x; i;  i -= lowbit(i)) res += v[i]; 
    return res;
}

int main() {
    IO;
    int n, q;
    cin >> n >> q;
    string s;
    repn(i, 1, q) {
        cin >> s;
        int a, b;
        if (s == "?") {
            cin >> a >> b;
            bool yes = false;
            if (a > b) swap(a, b);
            if (get(b + 1) - get(a) == 0) yes = true;
            else if (get(n + 1) - get(b) + get(a + 1) == 0) yes = true;
            if (yes) cout << "possible\n";
            else cout << "impossible\n";
        }
        else {
            cin >> a;
            int upt;
            if (s == "+") upt = -1;
            else upt = 1;
            add(a + 1, upt);
        }
    }
    return 0;
}



