#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj[100001];
int subtree[100001];
bool visited[100001];

int dfs(int node) {
    visited[node] = true;
    subtree[node] = 1; 
    for (int next : adj[node]) {
        if (!visited[next]) {
            subtree[node] += dfs(next);
        }
    }
    return subtree[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) { 
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(r); 

    while (q--) {
        int x;
        cin >> x;
        cout << subtree[x] << '\n';
    }

    return 0;
}