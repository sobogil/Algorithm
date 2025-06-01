#include<bits/stdc++.h>
using namespace std;

int a,b,c;
int main(){
    cin >>a;
    while(a--){
        string s;
        cin >> s;
        int ret =0;
        int cnt =0;
        for(auto c : s){
            if(c=='O'){
                cnt++;
            }
            else cnt=0;
            ret += cnt;
        }
        cout <<ret<<'\n';
    }    
}