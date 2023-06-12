// Problem: Bill Total Value
// URL: https://codeforces.com/gym/328479/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[1100], ans[100];


int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    for(int i=1; i<100; i++) ans[i]='0';
    int st=1, ed, t, m=0;
    while(st<=n){
        ed=st;
        while(!isdigit(s[ed])) ed++;
        st=ed;
        while(isdigit(s[ed+1]) || s[ed+1]=='.') ed++;
        if(ed-2>st && s[ed-2]=='.') t=1;
        else t=4;
        int c=0;
        for(int i=ed; i>=st; i--){
            if(s[i]=='.'){ ans[t++]='.'; continue;}
            int a=s[i]-'0', b=ans[t]-'0';
            ans[t++]=(a+b+c)%10+'0';
            if(a+b+c>=10) c=1;
            else c=0;
        }
        while(c){
            if(t%4==3){ ans[t++]='.'; continue;}
            int a=ans[t]-'0';
            ans[t++]=(a+c)%10+'0';
            if(a+c>=10) c=1;
            else c=0;
        }
        m=max(m, t-1);
        st=ed+1;
    }
    ans[3]='.';
    m=max(m, 4);
    if(ans[1]==ans[2] && ans[1]=='0') t=4;
    else t=1;
    for(int i=m; i>=t; i--) printf("%c", ans[i]);
    printf("\n");
    return 0;
}

