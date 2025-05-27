#include<bits/stdc++.h>
using namespace std;


long long tree[4000001],a[1000001],lazy[4000001];
void build(int node,int s,int e){
    if(s==e){
        tree[node] = a[s];
    }else{
        int mid = (s+e)/2;
        build(node*2,s,mid);
        build(node*2+1,mid+1,e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void propa(int node,int s,int e){
    if(lazy[node]){
        tree[node] += (e-s+1)*lazy[node];
        if(s!=e){
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long sum(int s,int e,int node,int l,int r){
    propa(node,s,e);
    if(r< s || l > e)return 0;
    if(l <=s && e<=r) return tree[node];

    int mid = (s+e)/2;
    return sum(s,mid,node*2,l,r) + sum(mid+1,e,node*2+1,l,r);
}

void update(int s,int e,int node,int l,int r,long long diff){
    propa(node,s,e);
    if(r < s || e < l) return;
    if(l<=s&&e<=r){
        lazy[node] += diff;
        propa(node,s,e);
        return;
    }
    int mid = (s+e)/2;
    update(s,mid,node*2,l,r,diff);
    update(mid+1,e,node*2+1,l,r,diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int n,m,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++)cin >> a[i];
    build(1,1,n);

    for(int i=0;i<m+k;i++){
        int a1,b,c;
        long long d;
        cin >> a1;
        if(a1==1){
            cin >>b>>c>>d;
            update(1,n,1,b,c,d);
        }else{
            cin >>b>>c;
            cout << sum(1,n,1,b,c)<<'\n';
        }
    }
}

