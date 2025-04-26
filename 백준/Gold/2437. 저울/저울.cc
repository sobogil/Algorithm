#include<bits/stdc++.h>
using namespace std;

int n,a[1004],ret;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i] > ret+1) break;
        ret+=a[i];
    }
    cout << ret+1;
}