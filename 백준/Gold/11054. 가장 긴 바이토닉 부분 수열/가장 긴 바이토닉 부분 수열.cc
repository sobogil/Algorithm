#include <bits/stdc++.h>
using namespace std;

int n, a[1004];
int dp[1004][2]; // dp[i][0]: 증가 상태, dp[i][1]: 감소 상태

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int answer = 0;
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = 1; // 자기 자신만 포함

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                // 증가 상태일 때만 가능
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            if (a[j] > a[i]) {
                // 감소 상태는 증가 or 감소 둘 다에서 올 수 있음
                dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + 1);
            }
        }

        answer = max({answer, dp[i][0], dp[i][1]});
    }

    cout << answer << '\n';
}