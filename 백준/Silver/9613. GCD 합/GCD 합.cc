#include<bits/stdc++.h>
using namespace std;

int t,n,a[101];
int gcd(int a,int b){
    if(a==0)return b;
    return gcd(b%a,a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main(){
    cin >>t;
    while(t--){
        cin >>n;
        long long ret=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ret += gcd(a[i],a[j]);
            }
        }
        cout<< ret<<'\n';
    }
}