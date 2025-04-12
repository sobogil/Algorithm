#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,ret=2000000000,a[100004];
ll b[2];
int main(){
    cin >>n;
    for(int i=0;i<n;i++)cin >>a[i];
    sort(a,a+n);

    int st=0,en =n-1;
    while(st<en){
        ll mid = a[st] + a[en];
        if(abs(mid) < ret){
            ret = abs(mid);
            b[0]=a[st];
            b[1]=a[en];
        }
        if(mid < 0)st++;
        else{en--;}
    }
    cout <<b[0] << ' '<<b[1];
}