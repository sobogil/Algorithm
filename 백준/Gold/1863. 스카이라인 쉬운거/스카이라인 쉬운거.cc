#include<bits/stdc++.h>
using namespace std;
int n,ans;

int main(){
    cin >> n;
    stack<int> cnt;
    cnt.push(0);
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        
        while(cnt.size() && cnt.top() > y){
            cnt.pop();
            ans++;
        }
        if(cnt.size() && cnt.top() < y){
            cnt.push(y);
        }
    }
    cout<< ans + cnt.size() -1;
}