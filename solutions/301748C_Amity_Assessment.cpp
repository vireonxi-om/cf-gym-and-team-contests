// Problem: Amity Assessment
// URL: https://codeforces.com/gym/301748/problem/C
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int a[3], b[3], m[4], n[4], aa, ab, ba, bb;

int main()
{
	for(int i=0; i<4; ){ 
	    scanf("%c", &m[i]);
		if(m[i]!='\n') i++;
	} 
	for(int i=0; i<4; ){ 
	    scanf("%c", &n[i]);
		if(n[i]!='\n') i++;
	}
	int i=m[3]; m[3]=m[2];m[2]=i; i=n[3]; n[3]=n[2];n[2]=i;
	for(int i=0, j=0; i<4; i++ ){
		a[j]=m[i]; 
		if(a[j]==65) aa=j;
		if(a[j]==66) ab=j;
		if(a[j]!=88) j++;
	}	
	for(int i=0, j=0; i<4; i++ ){
		b[j]=n[i]; 
		if(b[j]==65) ba=j;
		if(b[j]==66) bb=j;
		if(b[j]!=88) j++;
	}
	
	if ((aa-ab==1||aa-ab==-2)&&(ba-bb==1||ba-bb==-2))
	    printf("YES\n");
	else if((aa-ab==-1||aa-ab==2)&&(ba-bb==-1||ba-bb==2))
	    printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
