// Problem: Petya and Exam
// URL: https://codeforces.com/gym/322393/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[30];
char s[30], p[110000], q[110000];

int main(){
    scanf("%s%s%d", s+1, p+1, &n);
    int t=strlen(s+1), l=strlen(p+1);
    for(int i=1; i<=t; i++){
        int now=s[i]-'a';
        a[now]=1;
    }
    int pos=0;
    for(int i=1; i<=l; i++){
        if(p[i]=='*'){ pos=i; break;}
    }
    while(n--){
        scanf("%s", q+1);
        int t=strlen(q+1);
        bool can=true;
        if(pos>0){
            int k=t-l+1;
            if(k<0) {can=false; printf("NO\n"); continue;}
            for(int i=1; i<=l; i++){
                int j=i;
                if(i==pos) continue;
                if(i>pos) j+=k-1;
                if(p[i]=='?' && a[q[j]-'a']  || p[i]==q[j]) continue;
                can=false;
            }
            for(int i=pos; i<k+pos; i++){
                if(a[q[i]-'a']==0) continue;
                can=false;
            }
        }
        else{
            if(t!=l) {can=false; printf("NO\n"); continue;}
            for(int i=1; i<=t; i++){
                if(p[i]=='?' && a[q[i]-'a'] || p[i]==q[i]) continue;
                can=false;
            }
        }
        if(can) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}