#include<bits/stdc++.h>
using namespace std;

string s,t;

int main(){
    cin >>s>>t;
    bool flag =0;
    while(s.size() != t.size()){
        if(!flag && t.back() == 'A'){
            t.pop_back();
        }
        else if(!flag && t.back() == 'B'){
            flag ^=1;
            t.pop_back();
        }else if(flag && t[0] == 'A'){
           t.erase(t.begin());
        }
        else if(flag && t[0] == 'B'){
            flag^=1;
            t.erase(t.begin());
        }
    }
    if(flag){
        reverse(t.begin(),t.end());

    }
        if(t==s)cout << 1;
        else cout << 0;
}