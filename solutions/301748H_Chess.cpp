// Problem: Chess
// URL: https://codeforces.com/gym/301748/problem/H
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;
int a[9][9], m, n, j, k;

int main()
{
	scanf("%c%d%c%c%d", &m, &n, &j, &j, &k);
	m-=96;j-=96; a[j][k]=1;
	int i, t, count=0;
	for(i=1;i<=8;i++){
		for(t=1; t<=8; t++){
			if(abs((m-i)*(n-t))==2 || abs((j-i)*(k-t))==2)
			a[i][t]=1;
			if(i==m) a[i][t]=1;
			if(t==n) a[i][t]=1;
		}	
	}
	for(i=1;i<=8;i++){
		for(t=1; t<=8; t++){
			if(a[i][t]==0) count++;
		}	
	}
	printf("%d", count);
	return 0;
}
