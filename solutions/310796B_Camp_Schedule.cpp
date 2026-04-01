// Problem: Camp Schedule
// URL: https://codeforces.com/gym/310796/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int pre[510000];
char s[510000], t[510000];

int main(){
    scanf("%s%s", &s, &t);
    int lt=strlen(t), ls=strlen(s);
    for(int i=1; i<lt; i++){
        int j=pre[i-1];
        while(j>0 && t[i]!=t[j]){
            j=pre[j-1];
        }
        if(t[i]==t[j]) j++;
        pre[i]=j;
    }
    int len=pre[lt-1], cnt0=0, cnt1=0, s1=0, s0=0, t0=0, t1=0;
    for(int i=0; i<lt; i++){ if(t[i]=='1') t1++; else t0++;}
    for(int i=0; i<ls; i++){ if(s[i]=='1') s1++; else s0++;}
    for(int i=len; i<lt; i++){ if(t[i]=='1') cnt1++; else cnt0++;}
    if(s1<t1 || s0<t0){ printf("%s\n", s); return 0;}
    s0-=t0; s1-=t1; printf("%s", t);
    int num0=cnt0==0? 600000:s0/cnt0, num1=cnt1==0? 600000:s1/cnt1;
    int num=min(num0, num1);
    for(int i=1; i<=num; i++){
        for(int j=len; j<lt; j++) printf("%c", t[j]);
    }
    for(int i=1; i<=s1-num*cnt1; i++) printf("1");
    for(int i=1; i<=s0-num*cnt0; i++) printf("0");
    printf("\n");
    return 0;
}