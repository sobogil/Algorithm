#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int n,m,segmax[4*MAX],segmin[4*MAX];
int a[MAX];
void build(int node,int s,int e){
    if(s==e)segmin[node] = segmax[node] = a[s];
    else{
        int mid = (s+e)/2;
        build(node*2,s,mid);
        build(node*2+1,mid+1,e);
        segmin[node] = min(segmin[node*2], segmin[node*2+1]);
        segmax[node] = max(segmax[node*2], segmax[node*2+1]);
    }
}

int findmin(int s,int e,int node,int l,int r){
    if(r < s || l > e) return 1e9;
    if(l <= s && e<=r) return segmin[node];

    int mid = (s+e)/2;
    return min(findmin(s,mid,node*2,l,r), findmin(mid+1,e,node*2+1,l,r));
}
int findmax(int s,int e,int node,int l,int r){
    if(r < s || l > e) return -1e9;
    if(l <= s && e<=r) return segmax[node];

    int mid = (s+e)/2;
    return max(findmax(s,mid,node*2,l,r), findmax(mid+1,e,node*2+1,l,r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n>>m;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    while(m--){
        int a,b;
        cin >>a>>b;
        int mn = findmin(1,n,1,a,b);
        int mx = findmax(1,n,1,a,b);
        cout << mn <<' '<<mx <<'\n';
    }
}