#include<bits/stdc++.h>
using namespace std;

int n,k;
string s,ans="0";

int main(){
    cin >>n>>k;
    cin >> s;
    k++;
    stack<char> stk;
    for(int i=s.size()-1;i>=0;i--){
        stk.push(s[i]);
    }
    while(stk.size()){
        if(k==0){
            while(stk.size()){
                ans += stk.top();
                stk.pop();
            }
            break;
        }
        char temp = stk.top();
        stk.pop();
        
        while(k>0&&ans.size()&&temp > ans.back()){
            ans.pop_back();
            k--;
        }
        ans+=temp;
    }
    if(k>0){
        for(int i=0;i<k;i++){
            ans.pop_back();
        }
    }
    cout << ans;
}