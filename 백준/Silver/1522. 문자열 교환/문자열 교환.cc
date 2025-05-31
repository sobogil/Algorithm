#include<bits/stdc++.h>
using namespace std;

string s;
int cnta,cntb,ret;
int main(){
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='a')cnta++;
    }
    ret= s.size();
    string s2 = s + s;

    for(int i=0;i<cnta;i++){
        if(s[i]=='b')cntb++;
    }
    ret = cntb;

    for(int i=1;i<s.size();i++){
        if(s2[i-1]=='b')cntb--;
        if(s2[i+cnta-1]=='b')cntb++;

        ret = min(ret,cntb);
    }
    cout<<ret;
}