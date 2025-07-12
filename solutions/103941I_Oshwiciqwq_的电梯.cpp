// Problem: Oshwiciqwq 的电梯
// URL: https://codeforces.com/gym/103941/problem/I
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

const int N = 210000;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;



int n, m, h, k, q;

struct res{
    int t_id, p_id, out;
    int x, y, z;
    friend bool operator < (res a, res b) {
        if (a.t_id != b.t_id) return a.t_id < b.t_id;
        if (a.out != b.out) return a.out < b.out;
        return a.p_id < b.p_id;
    }
};

vector<res> cur;
vector<pair<int, res>> ans;

struct train{
    int x, y, z;
    int tp;
}t[200];

struct ps{
    int pt;
    int x, y, z;
    int ex, ey, ez;
    int on, t_id;
}p[60];

void movetrain() {
    repn(i, 1, k) {
        if (t[i].tp == 0) {
            t[i].x += 1; 
            if (t[i].x > n) t[i].x = 1;
        }
        if (t[i].tp == 1) {
            t[i].y += 1; 
            if (t[i].y > m) t[i].y = 1;
        }
        if (t[i].tp == 2) {
            t[i].z += 1; 
            if (t[i].z > h) t[i].z = 1;
        }
    }
}

void check_p(int id) {
    res now; bool can = false;
    ps pnow = p[id];
    if (pnow.on) {
        bool yes = false;
        train tnow = t[p[id].t_id];
        p[id].x = tnow.x; p[id].y = tnow.y; p[id].z = tnow.z;
        if (tnow.tp == 0 && tnow.x == pnow.ex) yes = true;
        else if (tnow.tp == 1 && tnow.y == pnow.ey) yes = true;
        else if (tnow.tp == 2 && tnow.z == pnow.ez) yes = true;
        if (yes){
            can = true;
            p[id].on = 0;
            now.out = 0; now.p_id = id;
            now.t_id = p[id].t_id; now.x = tnow.x;
            now.y = tnow.y; now.z = tnow.z;
        } 
    }
    else {
        int p_tp = 0;
        if (pnow.ex == pnow.x){
            p_tp = 1;
            if (pnow.ey == pnow.y) {
                p_tp = 2;
                if (pnow.ez == pnow.z) p_tp = 3;
            }
        }
        if (p_tp != 3) {
            repn(i, 1, k) {
                if (t[i].tp != p_tp) continue;
                if (t[i].x != pnow.x) continue;
                if (t[i].y != pnow.y) continue;
                if (t[i].z != pnow.z) continue;
                p[id].on = 1;
                p[id].t_id = i;
                can = true;
                now.out = 1; now.p_id = id;
                now.t_id = p[id].t_id; now.x = pnow.x;
                now.y = pnow.y; now.z = pnow.z;
                break;
            }
        }
    }
    if (can) cur.pb(now);
}

int main() {
    IO;
    cin >> n >> m >> h >> k;
    repn(i, 1, k) {
        cin >> t[i].tp >> t[i].x >> t[i].y >> t[i].z;
    }
    cin >> q;
    repn(i, 1, q) {
        cin >> p[i].pt >> p[i].x >> p[i].y >> p[i].z;
        cin >> p[i].ex >> p[i].ey >> p[i].ez;
    }
    repn(i, 0, 600) {
        if (i > 0) movetrain();
        cur.clear();
        repn(j, 1, q) {
            if (i < p[j].pt) continue;
            check_p(j);
        }
        sort(all(cur));
        for (auto x : cur) ans.pb(mp(i, x));
    }
    for (auto x : ans){
        string str;
        if (x.se.out) str = " IN";
        else str = " OUT";
        cout << "[" << x.fi << "s] Person " << x.se.p_id << str;
        cout << " Elevator " << x.se.t_id << " at (" << x.se.x << ", ";
        cout << x.se.y << ", " << x.se.z << ")\n";
    }
    return 0;
}



