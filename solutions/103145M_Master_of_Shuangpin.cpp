// Problem: Master of Shuangpin
// URL: https://codeforces.com/gym/103145/problem/M
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
char c;
map<string, char> s;

void pre(){
    s["q"]='q'; s["w"]='w'; s["r"]='r'; s["t"]='t';
    s["iu"]='q'; s["ei"]='w'; s["e"]='e'; s["uan"]='r'; s["ue"]='t';
    s["y"]='y'; s["un"]='y'; s["u"]='u'; s["sh"]='u'; s["i"]='i'; s["ch"]='i';
    s["o"]='o'; s["uo"]='o'; s["p"]='p';  s["ie"]='p';  s["a"]='a';
    s["s"]='s'; s["ong"]='s'; s["iong"]='s'; s["d"]='d'; s["ai"]='d';
    s["f"]='f'; s["en"]='f'; s["g"]='g'; s["eng"]='g';
    s["h"]='h'; s["ang"]='h'; s["j"]='j'; s["an"]='j';
    s["k"]='k'; s["uai"]='k'; s["ing"]='k';
    s["l"]='l'; s["uang"]='l'; s["iang"]='l';
    s["z"]='z'; s["ou"]='z'; s["x"]='x'; s["ia"]='x'; s["ua"]='x';
    s["c"]='c'; s["ao"]='c';
    s["v"]='v'; s["zh"]='v'; s["ui"]='v';
    s["b"]='b'; s["in"]='b'; s["n"]='n'; s["iao"]='n';
    s["m"]='m'; s["ian"]='m';
}

bool yes(char t){
    if(t=='a' || t=='e' || t=='i' || t=='o' || t=='u') return true;
    else return false;
}

void work(){
    int len=a.size();
    if(len==1){
        cout<<a<<a; return;
    }
    else if(len==2){
        cout<<a; return;
    }
    int k=0;
    while(!yes(a[k])) k++;
    if(k==0){
        cout<<a[k];
        cout<<s[a];
        return;
    }
    else{
        cout<<s[a.substr(0, k)];
        if(k<len) cout<<s[a.substr(k, len-k)];
    }
}

int main(){
    int d=1;
    pre();
    while(d!=-1){
        d=scanf("%c", &c);
        if(d==-1) break;
        if(c==' '){
            if(a.size()) work();
            printf(" ");
            a.clear();
            continue;
        }
        else if(c=='\n'){
            if(a.size()) work();
            printf("\n");
            a.clear();
            continue;
        }
        else a+=c;
    }
    if(a.size()) work();
    printf("\n");
    if(d==-1) return 0;
}
