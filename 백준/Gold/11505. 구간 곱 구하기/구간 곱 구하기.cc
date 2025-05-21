#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
const int MAX = 1000001;
ll seg[4*MAX];
ll a[MAX];
ll DIV = 1000000007;

ll build(int node, int s,int e){
    if(s==e) return seg[node] = a[s];
    else{
        int mid = (s+e)/2;
        return seg[node] = build(node*2,s,mid)*build(node*2+1,mid+1,e)%DIV;
    }
}

ll mul(int s,int e, int node, int l,int r){
    if(r < s || l > e) return 1;
    if(l <=s && e<= r) return seg[node];

    int mid = (s+e)/2;
    return mul(s,mid,node*2,l,r)*mul(mid+1,e,node*2+1,l,r)%DIV;
}

void update(int s,int e,int node,int idx,ll dif){
    if(idx<s || idx >e) return ;
    if (s == e) {
        seg[node] = a[idx] = dif;
        return;
    }
    int mid=(s+e)/2;
    update(s,mid,node*2,idx,dif);
    update(mid+1,e,node*2+1,idx,dif);
    seg[node] = seg[node * 2] * seg[node * 2 + 1] % DIV;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>m>>k;

    for(int i=1;i<=n;i++) cin >>a[i];
    build(1,1,n);
    int cnt = k+m;
    while(cnt--){
        int x,y,z;
        cin >>x>>y>>z;
        if(x==1){
            update(1,n,1,y,z);
        }else{
            cout <<mul(1,n,1,y,z) <<'\n';
        }
    }
}