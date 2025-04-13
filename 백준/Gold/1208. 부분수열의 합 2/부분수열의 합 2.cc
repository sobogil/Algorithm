#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ret,s;
vector<ll> a,ret1,ret2;
void go(vector<ll> &v,vector<ll> &ret,int st, int en, ll sum){
    if(st == en){
        ret.push_back(sum);
        return;
    }
    go(v,ret,st+1,en,sum);
    go(v,ret,st+1,en,sum+v[st]);
}

int main(){
    cin >>n>>s;
    a.resize(n);
    for(int i=0;i<n;i++)cin >>a[i];
    vector<ll> left(a.begin(),a.begin()+n/2);
    vector<ll> right(a.begin()+n/2,a.end());

    go(left, ret1, 0, left.size(), 0);
    go(right, ret2, 0, right.size(), 0);

    sort(ret1.begin(),ret1.end());

    ll result =0;
    for(int i=0;i<ret2.size();i++){
        ll target = s - ret2[i];
        result += upper_bound(ret1.begin(),ret1.end(), target) 
                    - lower_bound(ret1.begin(),ret1.end(), target);
    }
    if(s==0) result--;
    cout <<result;
}