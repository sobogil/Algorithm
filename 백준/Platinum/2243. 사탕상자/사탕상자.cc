#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
const int MAX = 1000000;
int tree[MAX*4];

void update(int node,int st,int en,int idx,int val){
    if(idx<st || en<idx)return;
    tree[node] += val;
    if(st == en)return;
    int mid = (st+en)/2;
    update(node*2, st, mid, idx, val);
    update(node*2+1,mid+1,en,idx,val);
}

int find(int node,int st,int en, int k){
    if(st==en)return st;
    int mid = (st+en)/2;
    if(tree[node*2] >= k){
        return find(node*2,st,mid,k);
    }else{
        return find(node*2+1,mid+1,en,k- tree[node*2]);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a==1){  
            cin >> b;
            int val = find(1,1,MAX,b);
            cout << val<<'\n';
            update(1,1,MAX,val,-1);
        }else{
            cin >>b>>c;
            update(1,1,MAX,b,c);
        }
    }
}