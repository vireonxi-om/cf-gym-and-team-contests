// Problem: Riana and Fiber Chatroom
// URL: https://codeforces.com/gym/102556/problem/F
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, yes[110000];
vector<int> ans;

int main(){
    scanf("%d", &n);
    int y, m, d; char c;
    int l=110000, r=0;
    for(int i=1; i<=n+1; i++){
        scanf("%d%c%d%c%d", &y, &c, &m, &c, &d);
        if(m==1 || m==2 && d<=28) yes[y]=1;
        l=min(l, y);
        r=max(r, y);
    }
    int cnt=0;
    for(int i=l+1; i<=r; i++){
        if(yes[i]) continue;
        cnt++;
        ans.push_back(i);
    }
    printf("%d\n", cnt);
    for(auto x: ans){
        printf("%d-02-10\n", x);
    }
    return 0;
}

