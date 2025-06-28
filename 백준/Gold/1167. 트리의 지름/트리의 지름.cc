#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> adj[100001];
bool visited[100001];
int farthest_node;
int max_dist;

void dfs(int node, int dist) {
    visited[node] = true;
    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = node;
    }

    for (auto [next, weight] : adj[node]) {
        if (!visited[next]) {
            dfs(next, dist + weight);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int from;
        cin >> from;
        while (1) {
            int to, weight;
            cin >> to;
            if (to == -1) break;
            cin >> weight;
            adj[from].emplace_back(to, weight);
        }
    }

    // 1. 임의의 노드(1)에서 가장 먼 노드 찾기
    max_dist = 0;
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    // 2. 그 노드에서 다시 DFS → 최대 거리 찾기
    max_dist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farthest_node, 0);

    cout << max_dist << '\n';
}