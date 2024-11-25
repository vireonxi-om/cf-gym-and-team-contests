// Problem: Saving the City
// URL: https://codeforces.com/gym/302311/problem/A
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char m[110000];
int a, b, total, num, cost, start;
void solve()
{
	memset(m,'0',sizeof(m)); total=0; num=0; cost=0; start=0;
	scanf("%d%d", &a, &b); getchar();
	for(int i=1; ; i++){
		scanf("%c", &m[i]);
		if(m[i]=='\n') { if(m[i-1]=='1') total++; break;}
		if(m[i]=='0') {
			if(m[i-1]=='1') total++;
			num++;
		}
		if(m[i]=='1'){
			if(m[i-1]=='0') {
				if(num*b<a && start==1) {total--; cost+=b*num; } 
			}
			num=0;
			start=1;
		}
	}
	cost+=total*a;
	printf("%d\n", cost);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
 } 
