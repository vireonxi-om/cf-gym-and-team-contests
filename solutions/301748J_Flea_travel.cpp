// Problem: Flea travel
// URL: https://codeforces.com/gym/301748/problem/J
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<10; i++){
		if((int)pow(2,i)==n){
			printf("YES");
			return 0;
		}
    }
	printf("NO");
	return 0;
} 
