#include<bits/stdc++.h>
using namespace std;

int parent[100001];
int n,m;

struct Edge{
    int u,v,cost;
    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
};

int find(int x){
    if(x == parent[x])return x;
    return parent[x] = find(parent[x]);
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b)parent[b] = a;
}
vector<Edge> v;
int main(){
    cin >>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end());

    for(int i=1;i<=n;i++) parent[i] = i;
    int total=0,last=0;
    for(auto e: v){
        if(find(e.u)!=find(e.v)){
            merge(e.u,e.v);
            total += e.cost;
            last = e.cost;
        }
    }
    cout << total-last;
}