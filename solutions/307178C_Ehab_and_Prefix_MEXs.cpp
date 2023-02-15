// Problem: Ehab and Prefix MEXs
// URL: https://codeforces.com/gym/307178/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[1100000], b[1100000], now;

int main(){
    scanf("%d", &n);
    for(int i=0; i<=2*n; i++) b[i]=1;
    bool can =true;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i]>i) can=false;
        else if(i>1 && a[i]<a[i-1]) can=false;
        b[a[i]]=0;
    }
    if(can){
        now=0;
        for(int i=1; i<=n; i++){
            if(i>1 && a[i]!=a[i-1]) printf("%d ", a[i-1]);
            else{
                while(b[now]==0) now++;
                printf("%d ", now); now++;
            }
        }
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
