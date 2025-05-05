#include<bits/stdc++.h>
using namespace std;

int n,t,k;
vector<int> p(1000001,-1);

int find(int x){
    if(p[x]<0)return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return false;
    if(p[v] < p[u])swap(v,u);
    if(p[v]==p[u])p[u]--;
    p[v] =u;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >>t;

    for(int i=1;i<=t;i++){
        cout << "Scenario "<<i<<":"<<'\n';
        cin >>n;
        cin>>k;

        fill(p.begin(),p.begin()+n+1,-1);

        for(int j=0;j<k;j++){
            int a,b;
            cin >> a>>b;
            uni(a,b);
        }
        cin >>k;
        for(int j=0;j<k;j++){
            int a,b;
            cin >> a>>b;
            if(find(a)==find(b)){
                cout <<1<<'\n';
            }else{
                cout <<0<<'\n';
            }
        }
        cout <<'\n';
    }
}