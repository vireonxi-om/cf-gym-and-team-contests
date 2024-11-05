// Problem: Chess Cheater
// URL: https://codeforces.com/gym/302311/problem/D
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
char a[110000];
pair <int, int> zero[55000];
int n, k, sum;

void solve()
{
	a[0]=0; sum=0;
	scanf("%d%d", &n, &k); getchar();
	int count=0, j=1, one=0;
	for(int i=1; i<=n; i++){
		scanf("%c", &a[i]);
		if(a[i]=='L') {
			a[i]=0;
			if(a[i-1]==1){
				zero[j].sc=i; count++;
			}
			else if(count>0) count++;
		}
		else{
			a[i]=1; one =i;
			if(a[i-1]==0 && count>0){
				zero[j].fr=count; count=0; j++;}
		}
	}
	sort(zero+1,zero+j);
	for(int i=1; i<j && k>0; i++){
		for(int m=0; m<zero[i].fr && k>0;m++){
			a[zero[i].sc+m]=1; k--;}
	}
	for(int i=one+1; i<=n && k>0; i++){
		if(a[i]==0){a[i]=1; k--;}
	}
	for(int i=one; i>0 && k>0; i--){
		if(a[i]==0){a[i]=1; k--;}
	}
	for(int i=1; i<=n; i++){
		if(a[i]==1){
			if(a[i-1]==0) sum+=1;
			else sum+=2;
		}
	}
	printf("%d\n", sum);
	
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
}
	
