#include<bits/stdc++.h>
using namespace std;
int n, a[1004],dp[1004];



int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[i] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[j] > a[i])
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp,dp+n+1);
}
