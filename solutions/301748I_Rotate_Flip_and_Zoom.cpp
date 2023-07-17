// Problem: Rotate, Flip and Zoom
// URL: https://codeforces.com/gym/301748/problem/I
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char a[110][110];
int row, col;

int main()
{
	scanf("%d%d", &row, &col);
	for(int j=1; j<=col; j++){
		getchar();
		for(int i=1; i<=row; i++){
			scanf("%c", &a[i][j]);
		}
	}
	for(int i=1; i<=row; i++){
		for(int j=1; j<=col; j++){
			printf("%c%c", a[i][j],a[i][j]);
		}
		printf("\n");
		for(int j=1; j<=col; j++){
			printf("%c%c", a[i][j],a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
