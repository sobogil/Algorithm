#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    while(1){
        cin >> s;
        if(s=="0")return 0;
        string cs = s;
        reverse(s.begin(),s.end());
        if(cs == s){
            cout << "yes"<<'\n';
        }else{
            cout << "no"<<'\n';
        }
    }
}