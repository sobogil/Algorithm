#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100001;
ll a[MAX],tree[4*MAX];
int n,q,a1,b,x,y;

void build(int node,int s,int e){
    if(s==e) tree[node] = a[s];
    else{
        int mid = (s+e)/2;
        build(node*2,s,mid);
        build(node*2+1, mid+1, e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll sum(int s,int e,int node,int l,int r){
    if(r<s || l>e)return 0;
    if(l<=s&&e<=r) return tree[node];

    int mid = (s+e)/2;

    return sum(s,mid,node*2,l,r) + sum(mid+1,e,node*2+1,l,r);
}

void update(int s,int e,int node,int idx,int dif){
    if(idx < s ||idx > e) return;
    if(s == e){
        tree[node] = a[idx] = dif;
        return;
    }
    int mid = (s+e)/2;
    update(s,mid,node*2,idx,dif);
    update(mid+1,e,node*2+1,idx,dif);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n>>q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    while(q--){
        cin >>x>>y>>a1>>b;
        if(y<x) swap(x,y);
        cout << sum(1,n,1,x,y)<<'\n';
        update(1,n,1,a1,b);
    }
}