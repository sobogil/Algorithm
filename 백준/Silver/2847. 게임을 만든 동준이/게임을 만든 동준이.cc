#include<bits/stdc++.h>
using namespace std;

int n,a[104],ret,sum;

int main(){
    cin >>n;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }


    for(int i=n-2;i>=0;i--){
        if(a[i] >= a[i+1]){
            sum = a[i]-a[i+1] +1;
            a[i] -= sum;
            ret += sum;
        }
    }
    cout <<ret;
}