// Problem: Numbers on Whiteboard
// URL: https://codeforces.com/gym/301456/problem/G
// Rating: 1000
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, i, j;

void solve(void)
{
	scanf("%d", &n);
	printf("%d\n", 2);
	if(n==2){
		printf("%d %d\n",1, 2);
	}
	else{
		printf("%d %d\n%d %d\n", n, n-2, n-1, n-1);
	    for(i=2;i<=n-2;i++){
		    printf("%d %d\n", n-i+1, n-i-1);
	    }
	}
	
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
