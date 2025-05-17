#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int to, cost;
};

int main() {
    int N, D;
    cin >> N >> D;

    vector<vector<Edge>> graph(D + 1);

    for (int i = 0; i < D; ++i) {
        graph[i].push_back({i + 1, 1});
    }

    for (int i = 0; i < N; ++i) {
        int s, e, c;
        cin >> s >> e >> c;
        if (e <= D && e - s > c) { 
            graph[s].push_back({e, c});
        }
    }

    vector<int> dist(D + 1, 1e9);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto& edge : graph[cur]) {
            int next = edge.to;
            int cost = edge.cost;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }

    cout << dist[D] << '\n';
    return 0;
}