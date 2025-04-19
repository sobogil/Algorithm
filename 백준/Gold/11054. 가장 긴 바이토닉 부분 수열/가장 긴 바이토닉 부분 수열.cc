#include<bits/stdc++.h>
using namespace std;

int n,a[1004],dp[1004][1004][2],flag;

int go(int k,int prev,int flag){
    if(k>=n){
        return 0;
    }

    int &ret = dp[k][prev][flag];
    if(ret) return ret;

    if(a[k] > prev && !flag)
    ret = max(ret, go(k+1,a[k],0)+1);
    if(a[k] < prev){
        ret = max(ret, go(k+1,a[k],1)+1);
    }
    ret = max(ret, go(k+1,prev,flag));

    return ret;
}

int main(){
    cin >>n;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << go(0,0,0);
}