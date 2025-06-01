#include<bits/stdc++.h>
using namespace std;

string s;

int f0,f1;

int main(){
    cin >> s;
    for(auto c :  s){
        if(c=='0')f0++;
        else f1++;
    }
    int zcnt = f0/2;
    int ocnt = f1/2;
    string ret;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1' && ocnt > 0){
            ocnt--;
            continue;
        }else{
            ret += s[i];
        }
    }
    reverse(ret.begin(),ret.end());
    // cout << ret;
    string ans;
    for(int i=0;i<ret.size();i++){
        if(ret[i]=='0' && zcnt > 0){
            zcnt--;
            continue;
        }else{
            ans += ret[i];
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
}