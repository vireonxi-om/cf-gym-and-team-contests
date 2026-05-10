// Problem: Short Program
// URL: https://codeforces.com/gym/320372/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[10];

int main(){
    scanf("%d%d", &n);
    for(int i=0; i<10; i++) a[i]=-1;
    char s[10]; int num, cur[10];
    while(n--){
        scanf("%s%d", &s, &num);
        int now=0;
        while(num){
            cur[now]=num%2;
            num/=2; now++;
        }
        for(int i=now;i<10; i++) cur[i]=0;
        if(s[0]=='|'){
            for(int i=0; i<10; i++){
                if(cur[i]==1) a[i]=1;
            }
        }
        else if(s[0]=='&'){
            for(int i=0; i<10; i++){
                if(cur[i]==0) a[i]=0;
            }
        }
        else{
            for(int i=0; i<10; i++){
                if(cur[i]==1){
                    if(a[i]==-1) a[i]=-2;
                    else if(a[i]==-1) a[i]=-1;
                    else a[i]=1-a[i];
                }
            }
        }
    }
    int ad=0, o=0, xr=0;
    for(int i=0; i<10; i++){
        int t=1<<i;
        if(a[i]==-2) xr+=t;
        if(a[i]==1) o+=t;
        if(a[i]!=0) ad+=t;
    }
    printf("3\n");
    printf("& %d\n", ad);
    printf("| %d\n", o);
    printf("^ %d\n", xr);
}
