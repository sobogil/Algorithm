#include<bits/stdc++.h>
using namespace std;
int n,a[1004],dp[1004][1004];

int go(int k,int now){
    if(k>n){
        return 0;
    }
    int &ret = dp[k][now];
    if(ret) return ret;
    if(a[k] > now)
    ret = max(go(k+1,now), go(k+1,a[k])+ a[k]);
    else ret = go(k+1,now);
    return ret;
}
int main(){
    cin >>n;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    cout << go(0,0);
}