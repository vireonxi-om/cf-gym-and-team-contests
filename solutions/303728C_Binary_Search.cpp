// Problem: Binary Search
// URL: https://codeforces.com/gym/303728/problem/C
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long n, x, p, result;

int main(){
    scanf("%lld%lld%lld", &n, &x, &p);
    result = 1;
    long long smaller = x - 1, larger = n - x;
    long long l = 0, r = n;
    while (l < r){
        long long middle = (l + r)/2;
        if (middle < p) {
            result *= smaller;
            result %= 1000000007;
            smaller--;
            l = middle + 1;
        }
        else if (middle > p){
            result *= larger;
            result %= 1000000007;
            larger--;
            r = middle;
        }
        else{
            l = middle + 1;
            while (l < r){
                r = (l + r)/2;
                result *= larger--;
                result %= 1000000007;
            }
            break;
        }
    }
    long long k = smaller + larger;
    while(k!=0) {
        result *= k; result %= 1000000007; k--;
    }

    printf("%lld\n", result);
}
