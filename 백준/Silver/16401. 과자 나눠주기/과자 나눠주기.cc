#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_VAL = 1e9;
ll n,ret,k,a[1000004];
bool check(ll mid){
    ll cnt =0;
    for(int i=0;i<n;i++){
        if(a[i]>=mid)cnt+= a[i]/mid;
    }
    return cnt >=k;
}
int main(){
    cin>>k;
    cin >>n;
    for(int i=0;i<n;i++)cin >>a[i];
    ll le = 1,ri=MAX_VAL;
    while(le<=ri){
       ll mid = (le+ri)/2;
       if(check(mid)){
        ret = mid;
        le = mid+1;
       } else{
        ri = mid-1;
       }
    }
    cout <<ret;
}