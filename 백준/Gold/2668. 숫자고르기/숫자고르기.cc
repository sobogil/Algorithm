#include<bits/stdc++.h>
using namespace std;
int a[101],cnt;
int visited[101],cycle[101];
vector<int> ret;
void dfs(int x,vector<int>& path){
    visited[x] = 1;
    path.push_back(x);
    int nx = a[x];
    if(!visited[nx]){
        dfs(nx,path);
    }else if(!cycle[nx]){
        for(int i=0;i<path.size();i++){
            if(path[i] == nx){
                for(int j=i;j<path.size();j++){
                    ret.push_back(path[j]);
                }
                break;
            }
        }
    }
    cycle[x] = 1;
}

int main() {

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> v;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            vector<int> path;
            dfs(i,path);
        }
    }
    sort(ret.begin(),ret.end());
    cout << ret.size()<<'\n';
    for(int i:ret){
        cout << i <<'\n';
    }
}