#include<bits/stdc++.h>
using namespace std;

int n,t;
int adj[100001];
set<vector<int>> s;
int visited[100001],finished[100001];
int ret;
void dfs(int x){
    visited[x] = 1;
    int nx = adj[x];

    if(!visited[nx]){
        dfs(nx);
    }else if(!finished[nx]){
        for(int i = nx;i!=x;i=adj[i]){
            ret++;
        }
        ret++;
    }
    finished[x] = 1;
}
int main(){
    cin >>t;

    while(t--){
        cin >>n;
        ret =0;
        for(int i=1;i<=n;i++){
            int a;
            cin >> adj[i];
            visited[i] = false;
            finished[i] = false;
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        cout << n-ret<<'\n';
    }
}