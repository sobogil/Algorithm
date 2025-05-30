#include<bits/stdc++.h>
using namespace std;

int n,dp[505][505];
int a[505];

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        int r,c;
        cin >>r>>c;
        if(i==0) a[i] = r;
        a[i+1] = c;

    }
    for(int len = 2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j = i + len-1;
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int c = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];
                dp[i][j] = min(dp[i][j],c);
            }
        }
    }

    cout << dp[1][n];
}