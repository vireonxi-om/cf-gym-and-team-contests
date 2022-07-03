// Problem: Knapsack
// URL: https://codeforces.com/gym/305901/problem/B
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w[210000];
ll W;

void solve(){
    scanf("%d %lld", &n, &W);
    ll sum=0; int cnt=0;
    set<int> index;
    for(int i=1; i<=n; i++) scanf("%d", &w[i]);
    for(int i=1; i<=n; i++){
        if(w[i]>=(W+1)/2 && w[i]<=W){
            printf("%d\n%d\n", 1, i);
            return;
        }
        else if(w[i]<(W+1)/2){
            sum=sum+w[i]; cnt++;
            index.insert(i);
            if(sum>=(W+1)/2){
                printf("%d\n", cnt);
                for(auto x:index) printf("%d ", x);
                printf("\n");
                return;
            }
        }
    }
    printf("%d\n", -1);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

