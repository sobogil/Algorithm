#include<bits/stdc++.h>
using namespace std;

int n,a[10],ans;
bool is[10];
vector<int> ret;
void go(int k){

    if(k==n){
        int temp=0;
        for(int i=0;i<n-1;i++){
            temp += abs(ret[i]-ret[i+1]);
        }
        ans = max(ans,temp);
        return;
    }

    for(int i=0;i<n;i++){
        if(is[i])continue;
        is[i]=1;
        ret.push_back(a[i]);
        go(k+1);
        is[i]=0;
        ret.pop_back();
    }
}

int main(){
    cin >>n;
    for(int i=0;i<n;i++)cin >>a[i];

    go(0);
    cout << ans;
}