#include<bits/stdc++.h>
using namespace std;

int c,n,dp[100001],a[22],b[22];


int main(){
    cin >>c>>n;

    for(int i=0;i<n;i++){
        cin >>a[i]>>b[i];
    }

    for(int i=0;i<100001;i++){
        for(int j=0;j<n;j++){
            if(i >= a[j]){
                dp[i] = max(dp[i], dp[i-a[j]] + b[j]);
            }
        }
    }
    for(int i=0;i<100001;i++){
        if(dp[i] >= c){
            cout << i;
            break;
        }
    }

}