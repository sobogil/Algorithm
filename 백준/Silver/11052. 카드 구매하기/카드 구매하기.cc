#include<bits/stdc++.h>
using namespace std;

int n,a[1004],dp[1004][1004];

int go(int k,int prev){
    if(k==n){
        return 0;
    }
    if(k>n){
        return -1e6;
    }
    int &ret = dp[k][prev];
    if(ret) return ret;

    for(int i=1;i<=n-k;i++){
        ret = max(ret,go(k+i,i)+a[i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    for(int i=1;i<=n;i++)cin >>a[i];

    cout << go(0,0);
}
