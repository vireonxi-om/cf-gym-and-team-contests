// Problem: Game with String
// URL: https://codeforces.com/gym/318001/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[5100];
vector<int> a[30];

int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    for(int i=1; i<=n; i++){
        a[s[i]-'a'].push_back(i);
    }
    int cnt=0;
    int yes[30];
    for(int i=0; i<26; i++){
        int num=0;
        for(int l=1; l<=n-1; l++){
            int now=0;
            for(int j=0; j<26; j++) yes[j]=0;
            for(auto x:a[i]){
                int pos=x+l; if(pos>n) pos-=n;
                yes[s[pos]-'a']++;
            }
            for(int j=0; j<26; j++) if(yes[j]==1) now++;
            num=max(num, now);
        }
        cnt+=num;
    }
    double ans=(double)cnt/n;
    printf("%.10f\n", ans);
    return 0;
}
