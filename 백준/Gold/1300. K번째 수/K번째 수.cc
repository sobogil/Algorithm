#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,ret,k;
bool check(ll mid){
    ll cnt =0;
    for(int i=1;i<=n;i++){
        cnt += min(n,mid/i);
    }
    return cnt >=k;
}
int main(){
    cin >>n>>k;
    ll le = 1,ri=n*n;
    while(le<=ri){
       ll mid = (le+ri)/2;
       if(check(mid)){
        ret = mid;
        ri = mid-1;
       } else{
        le = mid+1;
       }
    }
    cout <<ret;
}