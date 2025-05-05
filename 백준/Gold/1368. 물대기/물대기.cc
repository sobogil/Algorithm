#include<bits/stdc++.h>
using namespace std;

int n,w[303];
vector<pair<int,pair<int,int>>> v;

vector<int> p(303,-1);

int find(int x){
    if(p[x]<0)return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v){
    u = find(u);
    v = find(v);
    if(u==v) return false;
    if(p[u] < p[v]) swap(v,u);
    if(p[u]==p[v])p[u]--;
    p[v] = u;
    return true;
}

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        v.push_back({c,{i,n}});
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c;
            cin>>c;
            if(i>=j)continue;
            v.push_back({c,{i,j}});
        }
    }

    n;
    sort(v.begin(),v.end());

    int cnt=0,ans=0;
    for(int i=0;i<v.size();i++){
        int a,b,c;
        c = v[i].first;
        a = v[i].second.first;
        b = v[i].second.second;

        if(!uni(a,b))continue;

        cnt++;
        ans +=c;
        if(cnt == n)break;
    }
    cout << ans;
}