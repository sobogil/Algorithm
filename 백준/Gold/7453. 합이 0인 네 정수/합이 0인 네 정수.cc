#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,y,x,ret,a[4004],b[4004],c[4004],d[4004];
vector<ll> ab,cd;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i]>>b[i]>>c[i]>>d[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    }
    sort(cd.begin(),cd.end());

    for(ll target : ab){
        ret += upper_bound(cd.begin(),cd.end(),-target) - lower_bound(cd.begin(),cd.end(),-target);
    }
    
    cout <<ret;
}