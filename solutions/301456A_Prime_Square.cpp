// Problem: Prime Square
// URL: https://codeforces.com/gym/301456/problem/A
// Rating: 900
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int a[500], n;

void find(void)
{
	int i, j=2, count=0, find;
	a[1]=2; 
	for(i=2;;i++){
		find=1;
		for(int k=2; k<=i/2+1; k++){
			if(i%k==0) find=0; 	
			}
			if(find){
				a[j]=i;j++;
				if(i>99)
				count++;
			}
			if(count==300) break;
	}

}

void solve(void)
{
	int i;
	scanf("%d",&n);
	for(i=1; ;i++){
		if(a[i]>n-1){
			break;
		}
	}
	for(int k=1;k<=n;k++){
		for(int m=1; m<=n; m++){
			if(m!=k) printf("%d ",1);
			else{
				int can=0;
				while(can==0){
					can=1;
					for(int j=i-1; j>0; j--){
					if(a[i]-n+1==a[j]) {i++;can=0;break;}
			        }
				}
				printf("%d ", a[i]-n+1);i++;
			}
		}
		printf("\n");
	}
}

int main()
{
    int t;
    find();
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
