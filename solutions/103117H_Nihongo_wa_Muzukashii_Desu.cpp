// Problem: Nihongo wa Muzukashii Desu
// URL: https://codeforces.com/gym/103117/problem/H
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false);
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a;i<n;i++)
#define repn(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pern(i,a,n) for (int i=n;i>=a;i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N=110000;
const int M=1100000;
const LL mod=1e9+7;

string s;
int T;
int check(string s1,string s2)
{
	int n=s1.size();
	int m=s2.size();
	if (n<m) return 0;
	if (s1.substr(n-m,m)==s2) return 1;
	return 0;
}
string change(string s1,string s2,string s3)
{
	if (s1=="ikimasu") return "itte";
	int n=s1.size();
	int m=s2.size();
	string res=s1.substr(0,n-m);
	res=res+s3;
	return res;
}
int main()
{
	IO;
	cin>>T;
	while (T--)
	{
		cin>>s;
		if (check(s,"chimasu")) s=change(s,"chimasu","tte");
		else if (check(s,"rimasu")) s=change(s,"rimasu","tte");
		else if (check(s,"mimasu")) s=change(s,"mimasu","nde");
		else if (check(s,"bimasu")) s=change(s,"bimasu","nde");
		else if (check(s,"nimasu")) s=change(s,"nimasu","nde");
		//else if (check(s,"ikimasu")) s=change(s,"ikimasu","itte");
		else if (check(s,"kimasu")) s=change(s,"kimasu","ite");
		else if (check(s,"gimasu")) s=change(s,"gimasu","ide");
		else if (check(s,"shimasu")) s=change(s,"shimasu","shite");
		cout<<s<<endl;
	}
	return 0;
}