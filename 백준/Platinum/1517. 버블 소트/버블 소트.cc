#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,result;
vector<int> a;

void mergesort(ll s,ll e){
    if(s >= e) return;
    ll mid = (s+e)/2;

    mergesort(s,mid);
    mergesort(mid+1,e);
    vector<ll> tmp;
    ll l = s,r = mid + 1,idx = s;

    while (l <= mid && r <= e) {
        if (a[l] <= a[r]) {
            tmp.push_back(a[l++]);
        } else {
            tmp.push_back(a[r++]);
            result += (mid - l + 1); 
        }
    }

    while (l <= mid) tmp.push_back(a[l++]);
    while (r <= e) tmp.push_back(a[r++]);

    for (ll i = s; i <= e; i++) {
        a[i] = tmp[i - s];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];
    mergesort(0,n-1);

    cout << result;
}