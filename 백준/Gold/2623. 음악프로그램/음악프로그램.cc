#include<bits/stdc++.h>
using namespace std;

int n,m,num,temp,a;
int deg[1004];
vector<int> adj[1004],ret;
queue<int> q;

int main(){
    cin >>n>>m;

    for(int i=0;i<m;i++){
        cin >>num;
        for(int j=0;j<num;j++){
            cin >> a;
            if(temp) {
                adj[temp].push_back(a);
                deg[a]++;
            }
            temp=a;
        }
        temp=0;
    }

    for(int i=1;i<=n;i++){
        // cout << deg[i]<<' ';
        if(!deg[i]) q.push(i);
    }
    while(q.size()){
        int cur = q.front();q.pop();
        ret.push_back(cur);
        // cout <<'\n';
        for(auto qwe : adj[cur]){
            deg[qwe]--;
            // cout << qwe <<' ';
            if(deg[qwe]==0) q.push(qwe);
        }
    }
    if(ret.size()!=n){
        cout<<0;
        return 0;
    }
    for(auto var:ret){
        cout << var<<'\n';
    }
}
