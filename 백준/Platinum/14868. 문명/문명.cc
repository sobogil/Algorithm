#include <bits/stdc++.h>


using namespace std;

int find_root(vector<int>& root, int a) {
    if (root[a] == a) return a;
    return root[a] = find_root(root, root[a]);
}

bool merge_root(vector<int>& root, int a, int b) {
    int root_a = find_root(root, a);
    int root_b = find_root(root, b);
    if (root_a != root_b) {
        root[root_b] = root_a;
        return true;
    }
    return false;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int N, K;
    cin >> N >> K;

    queue<tuple<int, int, int, int>> q;  // cur, day, y, x
    vector<int> root(K);
    for (int i = 0; i < K; ++i) root[i] = i;

    vector<vector<int>> arr(N, vector<int>(N, -1));

    for (int k = 0; k < K; ++k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
			
        q.emplace(k, 0, a, b);
    }

    int ans = 0;

   int merge_count = 0;
    while (!q.empty()) {
        auto [cur, day, y, x] = q.front(); q.pop();

        if (arr[y][x] != -1) {
            int t = arr[y][x];
            if (merge_root(root, cur, t)) {
                ans = day;
                merge_count ++;
            }
            continue;
        }
      if (merge_count == K-1) break;
      
        arr[y][x] = cur;

        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (arr[ny][nx] != -1) {
                int t = arr[ny][nx];
                if (merge_root(root, cur, t)) {
                    ans = day;
                    merge_count ++;
                }
                continue;
            }
						if(merge_count==K-1)break;
            q.emplace(cur, day + 1, ny, nx);
        }
			if(merge_count==K-1)break;
    }

    cout << ans << endl;
    return 0;
}
