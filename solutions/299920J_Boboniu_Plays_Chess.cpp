// Problem: Boboniu Plays Chess
// URL: https://codeforces.com/gym/299920/problem/J
// Rating: 1100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, i, j;
int main()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	printf("%d %d\n", a, b);
	for (i=n; i>a; i--) printf("%d %d\n", i, b);
	for (i=a-1; i>0; i--) printf("%d %d\n", i, b);
	for (j=1; j<=n/2; j++){
		for (i=1; i<b; i++) printf("%d %d\n", 2*j-1, i);
	    for (i=b+1; i<=m; i++) printf("%d %d\n", 2*j-1, i);
	    for (i=m; i>b; i--) printf("%d %d\n", 2*j, i);
	    for (i=b-1; i>0; i--) printf("%d %d\n", 2*j, i);
    }
    
    if(n%2==1){
    	for (i=1; i<b; i++) printf("%d %d\n", n, i);
    
	    for (i=b+1; i<=m; i++) printf("%d %d\n", n, i);
	}
	return 0;
}
