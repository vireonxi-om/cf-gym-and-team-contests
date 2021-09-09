// Problem: Riana and Distribution of Pie
// URL: https://codeforces.com/gym/102556/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        printf("%.6f ", (double)100/i);
    }
    printf("\n");
    return 0;
}

