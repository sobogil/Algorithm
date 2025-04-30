#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[32003];
int deg[32003];

int main(){
    cin >>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++){
        if(!deg[i])pq.push(i);
    }
    while(pq.size()){
        int cur = pq.top();pq.pop();
        cout << cur <<' ';
        for(auto var : adj[cur]){
            deg[var]--;
            if(deg[var]==0)pq.push(var);
        }
    }
}