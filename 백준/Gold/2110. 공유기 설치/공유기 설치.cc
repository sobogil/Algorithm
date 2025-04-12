#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_VAL =1000000000;
ll n,c,ret;
vector<ll> a;
bool check(ll d){
    ll cnt=1;
    ll last = a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last >=d){
            cnt++;
            last = a[i];
        }
    }
    return cnt>=c;
}

int main(){
    cin >>n>>c;
    for(int i=0;i<n;i++){
        int temp;
        cin >>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());

    ll st =1, en=a[n-1] - a[0];
    while(st <= en){
        ll mid = (st+en)/2;
        if(check(mid)){
            ret = mid;
            st = mid+1;
        }else{
            en = mid-1;
        }
    }
    cout <<ret;
}