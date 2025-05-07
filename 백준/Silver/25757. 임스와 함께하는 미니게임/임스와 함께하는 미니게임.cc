#include<bits/stdc++.h>
using namespace std;

int n,cnt;
char c;
string s;
map<string,int> m;

int main(){
    cin >>n>>c;

    for(int i=0;i<n;i++){
        cin >> s;
        if(!m[s])cnt++;
        m[s]=1;
    }
    int ret =0;
    if(c=='Y'){
        ret=1;
        cnt/=ret;
    }else if(c=='O'){
        ret=3;
        cnt/=ret;
    }else if(c=='F'){
        ret=2;
        cnt/=ret;
    }

    cout <<cnt;
}