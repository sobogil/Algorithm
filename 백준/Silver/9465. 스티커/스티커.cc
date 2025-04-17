#include<bits/stdc++.h>
using namespace std;

int t,n,dp[2][100004],a[2][100004];

int main(){
    cin >> t;
    while(t--){
        cin >>n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++) cin >>a[i][j];
        }

        memset(dp,0,sizeof(dp));

        dp[0][0] = a[0][0];
        dp[1][0] = a[1][0];
        if(n>1){
            dp[0][1] = dp[1][0] + a[0][1];
            dp[1][1] = dp[0][0] + a[1][1];
        }
        for(int i=2;i<=n;i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2] ) + a[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2] ) + a[1][i];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) <<'\n';
    }


}