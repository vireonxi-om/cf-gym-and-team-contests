// Problem: Mike and Shortcuts
// URL: https://codeforces.com/gym/328644/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000], b[210000];
queue<int> q;


int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){ scanf("%d", &a[i]); b[i]=-1; }
    q.push(1);
    b[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(b[a[now]]<0){ b[a[now]]=b[now]+1; q.push(a[now]);}
        if(now<n && b[now+1]<0){ b[now+1]=b[now]+1; q.push(now+1);}
        if(now>1 && b[now-1]<0){ b[now-1]=b[now]+1; q.push(now-1);}
    }
    for(int i=1; i<=n; i++) printf("%d ", b[i]);
    printf("\n");
    return 0;
}
