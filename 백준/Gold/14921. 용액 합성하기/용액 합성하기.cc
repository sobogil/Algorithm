#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,a[100001],ret=120000000;

int main(){
    cin >> n;

    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);

    int le = 0;
    int ri = n-1;
    int l=0,r=0;
    while(le < ri){
        ll target = a[le] + a[ri];
        if(abs(target) < ret){
            ret = abs(target);
            l = le;
            r = ri;
        }
        if(target < 0){
            le++;
        }else{ri--;}
    }
    cout <<a[l]+a[r];
}