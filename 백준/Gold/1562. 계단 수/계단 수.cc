#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9;
int N;
ll dp[101][10][1 << 10]; 

int main() {
    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int pos = 1; pos < N; pos++) {
        for (int digit = 0; digit <= 9; digit++) {
            for (int bit = 0; bit < (1 << 10); bit++) {
                if (dp[pos][digit][bit] == 0) continue;

                if (digit > 0) {
                    int next = digit - 1;
                    int nextBit = bit | (1 << next);
                    dp[pos + 1][next][nextBit] += dp[pos][digit][bit];
                    dp[pos + 1][next][nextBit] %= MOD;
                }
                if (digit < 9) {
                    int next = digit + 1;
                    int nextBit = bit | (1 << next);
                    dp[pos + 1][next][nextBit] += dp[pos][digit][bit];
                    dp[pos + 1][next][nextBit] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i][(1 << 10) - 1]) % MOD;
    }

    cout << ans << "\n";
}