#include<bits/stdc++.h>
using namespace std;

int n, dp[100004];
int INF = 987654321;

int main(){
    cin >>n;
    memset(dp,987650,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=(int)sqrt(i);j++){
            // cout << dp[i];
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    cout << dp[n];
}