#include<bits/stdc++.h>
using namespace std;

int n,t,dp[10004][3];

int go(int k,int now){
    if(k==n){
        return 1;
    }
    if(k>n){
        return 0;
    }
    int &ret = dp[k][now];
    if(ret!=-1) return ret;

    ret=0;
    ret += go(k+3,3);
    if(now<=2)
    ret += go(k+2,2);
    if(now<=1)
    ret += go(k+1,1);

    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>t;

    while(t--){
        cin >>n;
        memset(dp,-1,sizeof(dp));
        cout << go(0,0)<<'\n';
    }
}