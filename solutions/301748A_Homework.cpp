// Problem: Homework
// URL: https://codeforces.com/gym/301748/problem/A
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
#define N 110000
using namespace std;
int a[N],c[N],b[30],*d[30],k;

int main()
{
	int n=1, i, j, count=0;
	while(a[n-1]!='\n'){
		scanf("%c", &a[n]);
		for(j=1;j<=26;j++){
			if(a[n]-96==j){
				b[j]++;c[n]=j;}
		}
		n++;
	}
	n--; scanf("%d", &k);
	for(i=0;i<=26;i++) { 
	    if (b[i]!=0) count++;
	    d[i]=&b[i];
	}
	for(i=1;i<=26;i++){
		for(j=i+1;j<=26;j++){
			if(*d[j]<*d[i] && *d[j]>0) {int *a=d[i]; d[i]=d[j]; d[j]=a;}
		}
	}
	for(i=1;i<=26;i++){
		if(k==0) break;
		if (*d[i]!=0){
			for(j=*d[i];j>0;j--){
			   k--;
			   if(k==0) { j--; break;}
			}
			if(j==0) count--;
			int num=d[i]-d[0];// printf("\n%d %d %d\n", k, i, j);
			for (int m=1; j<*d[i];m++){
				if(c[m]==num){ c[m]=0; j++;}
			}
		}
		if(k==0) break;
	}
	printf("%d\n", count);
	for (int m=1; m<=n; m++){
		if(c[m]!=0) printf("%c", a[m]);
	}
	printf("\n");
	return 0;
}
