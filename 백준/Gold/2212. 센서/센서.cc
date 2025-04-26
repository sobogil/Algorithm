#include<bits/stdc++.h>
using namespace std;

int n,k,a[10004],b[10004];

int main(){
    cin >>n>>k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        b[i] = a[i] - a[i-1];
    }
    sort(b,b+n);
    int sum=0;
    for(int i=1;i<n-k+1;i++){
        sum +=b[i];
    }
    cout <<sum;
}