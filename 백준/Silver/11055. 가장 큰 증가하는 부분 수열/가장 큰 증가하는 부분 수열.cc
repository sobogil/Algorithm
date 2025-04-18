#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];
int dp[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = a[i]; // 초기값: 자기 자신만 사용하는 경우
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    cout << *max_element(dp, dp + n);
}