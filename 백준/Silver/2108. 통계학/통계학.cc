#include<bits/stdc++.h>
using namespace std;

int a[500005],n,sum,mn = 9999,mx;
map<int,int> cnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>a[i];
        sum += a[i];
        cnt[a[i]]++;
        // mx = max(a[i],mx);
        // mn = min(a[i],mn);
    }
    sort(a,a+n);
    int count=0;
    for(auto &p:cnt){
        if(mx < p.second){
            mn = p.first;
            mx = p.second;
            count=1;
        }
        else if(mx == p.second && count==1 && p.first != mn){
            mn = p.first;
            count=0;
        }
    }
    double k = (double)sum/n;
    cout << (int)round(k)<<'\n';
    cout<< a[n/2]<<'\n';
    cout << mn<<'\n';
    cout << a[n-1]-a[0];
}