#include <bits/stdc++.h>
using namespace std;

int n, a[1004], dp[1004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = max(dp[i], dp[i-j] + a[j]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}