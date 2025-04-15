#include<bits/stdc++.h>
using namespace std;

long long n,dp[99];

int main(){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    cin >>n;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}