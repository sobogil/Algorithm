#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e15;
ll n, m, k;
vector<pair<ll, ll>> adj[100004];
vector<ll> v;
ll dist[100001];

void dik(const vector<ll>& starts) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    fill(dist, dist + n + 1, INF); 

    for (ll s : starts) {
        dist[s] = 0;
        pq.push({0, s});
    }

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost > dist[u]) continue;

        for (auto [vtx, c] : adj[u]) {
            if (dist[vtx] > dist[u] + c) {
                dist[vtx] = dist[u] + c;
                pq.push({dist[vtx], vtx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c}); 
    }

    for (ll i = 0; i < k; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    dik(v);

    ll idx = -1;
    ll mx = -1;

    for (ll i = 1; i <= n; i++) {
        if (dist[i] != INF && dist[i] > mx) {
            mx = dist[i];
            idx = i;
        }
    }

    cout << idx << '\n' << mx << '\n';
}