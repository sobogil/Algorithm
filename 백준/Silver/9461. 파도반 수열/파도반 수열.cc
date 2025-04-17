#include<bits/stdc++.h>
using namespace std;

long long t,n,dp[104];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        dp[2]=1;
        for(int i=2;i<n;i++){
            dp[i+1] = dp[i-1] + dp[i-2];
        }
        cout << dp[n-1] << '\n';
    }
}