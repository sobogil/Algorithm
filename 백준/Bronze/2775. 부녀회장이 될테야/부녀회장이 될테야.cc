#include<bits/stdc++.h>
using namespace std;

int n,k,t,dp[15][15];


int main(){
    cin >> t;

    while(t--){
        cin >>k>>n;
        for(int i=1;i<=n;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        cout << dp[k][n] <<'\n';
        memset(dp,0,sizeof(dp));
    }
}