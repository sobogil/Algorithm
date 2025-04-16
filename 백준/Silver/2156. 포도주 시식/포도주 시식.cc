#include<bits/stdc++.h>
using namespace std;

int n,a[10004],dp[10004][3];

int go(int k,int cnt){
    if(k>=n){
        return 0;
    }
    int &ret = dp[k][cnt];
    if (ret != -1) return ret;
    if(cnt == 2){
        ret = go(k + 1, 0);
    }else{
        ret = max(ret, go(k+1, cnt+1) + a[k]);
        ret = max(ret, go(k + 1, 0));
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)cin >>a[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0,0);
}