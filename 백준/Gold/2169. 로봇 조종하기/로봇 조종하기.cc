#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];

    // 첫 행은 그냥 누적합으로 초기화
    dp[0][0] = arr[0][0];
    for(int j=1; j<M; j++) {
        dp[0][j] = dp[0][j-1] + arr[0][j];
    }

    // 각 행마다 처리
    for(int i=1; i<N; i++) {
        vector<int> leftToRight(M, INT_MIN);
        vector<int> rightToLeft(M, INT_MIN);

        // 왼쪽->오른쪽
        leftToRight[0] = dp[i-1][0] + arr[i][0];
        for(int j=1; j<M; j++) {
            leftToRight[j] = max(leftToRight[j-1], dp[i-1][j]) + arr[i][j];
        }

        // 오른쪽->왼쪽
        rightToLeft[M-1] = dp[i-1][M-1] + arr[i][M-1];
        for(int j=M-2; j>=0; j--) {
            rightToLeft[j] = max(rightToLeft[j+1], dp[i-1][j]) + arr[i][j];
        }

        // dp 업데이트
        for(int j=0; j<M; j++) {
            dp[i][j] = max(leftToRight[j], rightToLeft[j]);
        }
    }

    cout << dp[N-1][M-1] << "\n";

    return 0;
}