#include<bits/stdc++.h>
using namespace std;
int n, a[1004],dp[1004][1004];


int go(int k, int prev){
    if(k>=n)return 0;
    int &ret = dp[k][prev];
    if(ret) return ret;

    if(prev > a[k])
    ret = max(ret, go(k+1,a[k])+ 1);
    ret = max(ret, go(k+1,prev));
    return ret;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << go(0,*max_element(a,a+n)+1);
}
