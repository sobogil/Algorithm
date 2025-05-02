#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> mp;
map<int, string> mp2;
vector<int> adj[1004];
vector<int> tree[1004]; 
int indegree[1004];      

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        mp[names[i]] = i;
        mp2[i] = names[i];
    }

    sort(names.begin(), names.end()); 

    cin >> m;
    for (int i = 0; i < m; i++) {
        string child, parent;
        cin >> child >> parent;
        adj[mp[parent]].push_back(mp[child]);  
        indegree[mp[child]]++; 
    }

    vector<int> roots;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            roots.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int child : adj[cur]) {
            indegree[child]--;
            if (indegree[child] == 0) {
                tree[cur].push_back(child); 
                q.push(child);
            }
        }
    }

    cout << roots.size() << '\n';
    vector<string> rootNames;
    for (int r : roots) rootNames.push_back(mp2[r]);
    sort(rootNames.begin(), rootNames.end());
    for (string& name : rootNames) cout << name << ' ';
    cout << '\n';

    for (string& name : names) {
        int idx = mp[name];
        vector<string> childNames;
        for (int child : tree[idx]) {
            childNames.push_back(mp2[child]);
        }
        sort(childNames.begin(), childNames.end());
        cout << name << ' ' << childNames.size();
        for (string& cname : childNames) cout << ' ' << cname;
        cout << '\n';
    }
}