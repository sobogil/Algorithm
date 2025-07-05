#include<bits/stdc++.h>
using namespace std;

int n,m;
int p[500005];

int find(int x){
    if(x==p[x])return x;
    return p[x] = find(p[x]);
}

bool merge(int a,int b){
    a = find(a);
    b= find(b);
    if(a==b)return false;
    p[b] = a;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >>m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        if(!merge(a,b)){
            cout << i;
            return 0;
        }

    }
    cout << 0;
}