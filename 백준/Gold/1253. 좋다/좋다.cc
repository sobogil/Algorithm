#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a[2002],ret;
int main(){
    cin >>n;
    for(int i=0;i<n;i++) cin >>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int st =0,en =n-1;
        while(st<en){
            if(st==i){st++;continue;}
            if(en==i){en--;continue;}
            ll val = a[st]+a[en];
            if(val == a[i]){
                ret++;
                break;
            }
            if(val < a[i])st++;
            else{
                en--;
            }
        }
    }
    cout <<ret;
}