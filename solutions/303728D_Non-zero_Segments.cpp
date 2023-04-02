// Problem: Non-zero Segments
// URL: https://codeforces.com/gym/303728/problem/D
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum;
int n, result;

int main(){
    scanf("%d", &n);
    map <ll, int> cnt;
    sum = 0; cnt[0]++; result = 0;
    ll num;
    for(int i=0; i<n; i++){
        scanf("%lld", &num);
        sum+=num;
        cnt[sum]++;
        if (cnt[sum] == 2){
            result++;
            cnt.clear();
            cnt[sum-num]++;
            cnt[sum]++;
        }
    }
    printf("%d\n", result);
    return 0;
}
