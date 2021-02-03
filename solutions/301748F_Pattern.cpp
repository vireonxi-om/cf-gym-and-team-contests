// Problem: Pattern
// URL: https://codeforces.com/gym/301748/problem/F
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n;
char a[110000];

int main()
{
	scanf("%d", &n); getchar();
	int j, len;char num;
	for(int i=1; i<=n; i++){
		for(j=1; ;j++){
			scanf("%c", &num);
			if(num=='\n') {len=j-1; break;}
			if(num!=a[j] && num!='?'){
				if(a[j]==0) a[j]=num;
				else a[j]=1;
			}
		}
	}
	
	for(int i=1; i<=len; i++){
		if(a[i]==0) a[i]='x';
		else if(a[i]==1) a[i]='?';
		printf("%c",a[i]);
	}
	
	return 0;
}
