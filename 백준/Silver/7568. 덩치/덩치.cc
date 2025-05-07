#include <bits/stdc++.h>
using namespace std;

int n, x, y;
pair<int, int> p[55];
int ans[55];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        p[i] = {x, y};
    }

    for(int i=0; i<n; i++) {
        int rank = 1;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if(p[j].first > p[i].first && p[j].second > p[i].second) {
                rank++;
            }
        }
        ans[i] = rank;
    }

    for(int i=0; i<n; i++) cout << ans[i] << ' ';
}