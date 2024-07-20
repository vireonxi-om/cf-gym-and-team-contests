// Problem: Searching Local Minimum
// URL: https://codeforces.com/gym/329456/problem/D
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    scanf("%d", &n);
    int l=1, r=n, ans;
    while(r>=l){
        int mid=(l+r)/2, num1, num, num2;
        printf("? %d\n", mid);
        fflush(stdout);
        scanf("%d", &num);
        if(mid>1){
            printf("? %d\n", mid-1);
            fflush(stdout);
            scanf("%d", &num1);
        }
        else num1=1e7;
        if(mid<n){
            printf("? %d\n", mid+1);
            fflush(stdout);
            scanf("%d", &num2);
        }
        else num2=1e7;
        if(num1>num && num2>num){ ans=mid; break;}
        else if(num2>num) r=mid;
        else l=mid+1;
    }
    printf("! %d\n", ans);
    return 0;
}

