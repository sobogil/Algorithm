#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
    cin >>s;

    int cnt0=0;
    int cnt1=0;
    bool flag=0;
    if(s[0]=='1')flag=1;
    for(auto c : s){
        if(c=='0'&&flag==0){
            cnt0++;
            flag=1;
        }
        else if(c=='1'&&flag==1){cnt1++;flag=0;}
    }
    cout << min(cnt0,cnt1);
}