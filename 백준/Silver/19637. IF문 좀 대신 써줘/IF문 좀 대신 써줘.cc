#include<bits/stdc++.h>
using namespace std;

int n,k,ret,temp,b[100001];
string a[100001];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n>>k;
    for(int i=0;i<n;i++){
        cin >>a[i]>>b[i];
    }
    while(k--){
        cin >> temp;
        int idx= lower_bound(b,b+n,temp) - b;
        cout << a[idx] << '\n';
    }


}