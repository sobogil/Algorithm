#include<bits/stdc++.h>
using namespace std;

int t,a,b;
int visited[10001];
string bfs(int a,int b){
    visited[a]=1;
    queue<pair<int,string>> q;
    q.push({a,""});
    while(q.size()){
        int node = q.front().first;
        string ret = q.front().second;
        q.pop();
        if(node == b)return ret;

        int D = (node*2)%10000;
        if(!visited[D]){
            visited[D] = 1;
            q.push({D,ret+"D"});
        }

        int S = (node==0) ? 9999 : node-1;
        if(!visited[S]){
            visited[S] = 1;
            q.push({S,ret+"S"});
        }

        int L = (node%1000)*10 + node/1000; 
        if(!visited[L]){
            visited[L] = 1;
            q.push({L,ret+"L"});
        }

        int R = (node/10) + (node%10)*1000; 
        if(!visited[R]){
            visited[R] = 1;
            q.push({R,ret+"R"});
        }
    }
    return "";
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin >> t;

    while(t--){
        memset(visited,0,sizeof(visited));
        cin >> a>>b;
        cout << bfs(a,b)<<'\n';
    }
}