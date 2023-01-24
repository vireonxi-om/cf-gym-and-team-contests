// Problem: Sequence Transformation
// URL: https://codeforces.com/gym/312561/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<int> ans;

int main(){
    scanf("%d", &n);
    int sz=n, now=1;
    while(sz){
        if(sz==1){ ans.push_back(now); sz--;}
        else if(sz==3){
            ans.push_back(now);
            ans.push_back(now);
            ans.push_back(now*3);
            sz-=3;
        }
        else{
            int t=(sz+1)/2; sz-=t;
            for(int i=1; i<=t; i++) ans.push_back(now);
        }
        now*=2;
    }
    for(auto x:ans) printf("%d ", x);
    printf("\n");
}