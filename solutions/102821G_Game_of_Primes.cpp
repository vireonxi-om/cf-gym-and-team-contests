// Problem: Game of Primes
// URL: https://codeforces.com/gym/102821/problem/G
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
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int x, y, w, k;
int mind[N];
vector<int> primes;

bool isprime(int x) {
    auto it = lower_bound(primes.begin(), primes.end(), x);
    if (it != primes.end() && (*it) == x) return true;
    else return false;
}

bool check(int now) {
    bool can = false;
    int tot = primes.size();
    rep(i, 0, tot) {
        if (primes[i] <= k) continue;
        if (primes[i] > y) break;
        int next = primes[i] + now;
        if (next <= x){ if (isprime(next)) can = true;}
        else break;
    }
    return can;
}

void solve(){
    scanf("%d%d%d%d", &x, &y, &k, &w);
    if(x < y) swap(x, y);
    int now = x - y;
    int num1 = abs(now - 2), num2 = abs(now + 2);
    int num3 = abs(now - 1), num4 = abs(now + 1);
    bool yes = check(now), yes1 = check(num1), yes2 = check(num2);
    bool yes3 = check(num3), yes4 = check(num4);
    bool can = false;
    if (w == 0) {
        if (isprime(x) && isprime(y)) can = true;
        if (yes3 || yes4) can = true;
    }
    else {
        if (x == k || y == k) {
            printf("Bob\n"); return;
        }
        if (yes) can = true;
        if (yes1 && yes2) can = true;
    }
    if (can) printf("Alice\n");
    else printf("Bob\n");
}

int main(){
    int t;
    for(int i=2; i<=MAX; i++){
        if(mind[i] == 0){
            primes.emplace_back(i);
            mind[i]=i;
        }
        for(auto x: primes){
            if(x>mind[i] || x*i>MAX) break;
            mind[x*i]=x;
        }
    }
    scanf("%d", &t);
    repn(i, 1, t){
        printf("Case %d: ", i);solve();
    }
    return 0;
}