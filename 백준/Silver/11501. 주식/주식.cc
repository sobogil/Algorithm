#include<bits/stdc++.h>
using namespace std;

int n,t,a[1000001];

int main(){
    cin >>t;
    while(t--){
        cin >>n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        long long ret =0;
        int mx = 0;
        for(int i=n-1;i>=0;i--){
            if(a[i] > mx){
                mx = a[i];
            }else{
                ret += mx - a[i];
            }
        }
        cout << ret<<'\n';
    }
}