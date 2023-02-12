// Problem: Display
// URL: https://codeforces.com/gym/104013/problem/D
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

const int N = 1000100;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;

int n, w, h, s;
vector<vector<int>> p(40, vector<int>(2, 0));
vector<vector<string>> id(40, vector<string>(2, "NA"));

int main() {
    IO;
    cin >> n >> w >> h >> s;
    repn(i, 1, n) {
        string nm;
        cin >> nm;
        rep(j, 0, h) {
            string s;
            cin >> s;
            s = "." + s;
            int cnt = 0;
            rep(k, 1, s.length()) if (s[k] != s[k - 1]) cnt ++;
            int cnt1 = cnt;
            if (s[s.length() - 1] == '#') cnt++;
            //cout << cnt << " " << cnt1 << "\n";
            if (cnt >= p[j][0]) {
                p[j][0] = cnt;
                id[j][0] = nm;
            }
            if (cnt1 >= p[j][1]) {
                p[j][1] = cnt;
                id[j][1] = nm;
            }
        }
    }
    
    int ans = 1e9;
    string res;
    
    repn(i, 0, h) {
        if (p[i][0] == 0) continue;
        if (s <= p[i][1]) {
            if (ans > 1) {
                ans = 1; 
                res = id[i][1];
            }
        }
        else {
            int num = (s - p[i][1]) / p[i][0]; 
            if ((s - p[i][1]) % p[i][0]) num ++;
            if (num + 1 < ans){
                //cout << i;
                ans = num + 1;
                res = "";
                rep(j, 0, num) res += id[i][0];
                res += id[i][1];
            }
        }
        
    }
    /*
    
    repn(i, 0, h) {
        if (p[i][0] == 0) continue;
        int num = s / p[i][0]; 
        if (s % p[i][0]) num ++;
        cout << num << id[i][0] << "\n";
        if (num < ans){
            ans = num;
            res = "";
            rep(j, 0, num) res += id[i][0];
            cout << i << " " << res << "\n";
        }
    }
    */
    cout << res << "\n";
    return 0;
}



