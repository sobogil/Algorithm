#include <bits/stdc++.h>
using namespace std;

struct Team {
    int id;
    int totalScore;
    int submitCnt;
    int lastSubmit;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        vector<vector<int>> bestScore(n+1, vector<int>(k+1, 0));
        vector<int> submitCnt(n+1, 0);
        vector<int> lastSubmit(n+1, 0);

        for (int i=1; i<=m; i++) {
            int team, prob, score;
            cin >> team >> prob >> score;
            submitCnt[team]++;
            bestScore[team][prob] = max(bestScore[team][prob], score);
            lastSubmit[team] = i; // 마지막 제출 시간 기록
        }

        vector<Team> teams;
        for (int i=1; i<=n; i++) {
            int sum = 0;
            for (int j=1; j<=k; j++) sum += bestScore[i][j];
            teams.push_back({i, sum, submitCnt[i], lastSubmit[i]});
        }

        sort(teams.begin(), teams.end(), [](auto &a, auto &b) {
            if (a.totalScore != b.totalScore) return a.totalScore > b.totalScore;
            if (a.submitCnt != b.submitCnt) return a.submitCnt < b.submitCnt;
            return a.lastSubmit < b.lastSubmit;
        });

        for (int i=0; i<n; i++) {
            if (teams[i].id == t) {
                cout << i+1 << "\n"; // 등수는 1부터 시작
                break;
            }
        }
    }
}