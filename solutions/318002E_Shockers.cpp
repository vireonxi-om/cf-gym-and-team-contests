// Problem: Shockers
// URL: https://codeforces.com/gym/318002/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[30], b[30];
char s[110000];

int main(){
    scanf("%d", &n);
    for(int i=0; i<26; i++) a[i]=1;
    bool can=false;
    int cnt=0;
    while(n){
        scanf("%s", &s);
        if(s[0]=='.'){
            scanf("%s", &s);
            int t=strlen(s);
            for(int i=0; i<t; i++) a[s[i]-'a']=0;
        }
        else if(s[0]=='?' && n>1){
            scanf("%s", &s);
            if(can) cnt++;
            else a[s[0]-'a']=0;
        }
        else if(s[0]=='!'){
            scanf("%s", &s);
            if(can) cnt++;
            else{
                for(int i=0; i<26; i++) b[i]=0;
                int t=strlen(s);
                for(int i=0; i<t; i++) b[s[i]-'a']=1;
                for(int i=0; i<26; i++) if(b[i]==0) a[i]=0;
            }
        }
        n--;
        int now=0;
        for(int i=0; i<26; i++) now+=a[i];
        if(now==1) can=true;
    }
    printf("%d\n", cnt);
    return 0;
}

