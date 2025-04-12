#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000004],li[1000004],len;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        auto pos = lower_bound(li,li+len,a[i]);
        if(*pos==0) len++;
        *pos = a[i];
    }
    cout <<len;
}