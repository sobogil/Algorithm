#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100001];
int tree[400001];

void build(int node,int s,int e){
    if(s==e) tree[node] = a[s];
    else{
        int mid = (s+e) /2;
        build(node*2,s,mid);
        build(node*2+1,mid+1,e);
        tree[node] = min(tree[node*2],tree[node*2+1]);
    }
}

int findMin(int s,int e,int node,int l,int r){
    if(r < s || l > e)return 1e9;
    if(l<=s && e <= r) return tree[node];

    int mid =(s+e)/2;
    return min(findMin(s,mid,node*2,l,r),findMin(mid+1,e,node*2+1,l,r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>m;
    for(int i=1;i<=n;i++)cin >>a[i];
    build(1,1,n);

    while(m--){
        int a1,b;
        cin >>a1>>b;
        cout << findMin(1,n,1,a1,b)<<'\n';
    }
}
