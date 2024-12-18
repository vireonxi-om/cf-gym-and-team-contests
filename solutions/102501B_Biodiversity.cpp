// Problem: Biodiversity
// URL: https://codeforces.com/gym/102501/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

vector<string> v;
string s;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    string now = "."; int cnt = 0;
    string ans;
    bool yes = false;
    for (auto x: v) {
        if (x == now) cnt ++;
        else {
            if (cnt > n - cnt) {yes = true; ans = now;}
            now = x;
            cnt = 1;
        }
    }
    if (cnt > n - cnt){yes = true; ans = now;}
    if (yes) cout << ans << endl;
    else cout << "NONE" << endl;
    return 0;
}



