#include<bits/stdc++.h>
using namespace std;
int n, dp[1004][1004];


int go(int k,int now){
    if(k>=n){
        return 1;
    }
    int &ret = dp[k][now];
    if(ret) return ret;
    if(now <= 0)
    ret += go(k+1,0)%10007;
    if(now <= 1)
    ret += go(k+1,1)%10007;
    if(now <= 2)
    ret += go(k+1,2)%10007;
    if(now <= 3)
    ret += go(k+1,3)%10007;
    if(now <= 4)
    ret += go(k+1,4)%10007;
    if(now <= 5)
    ret += go(k+1,5)%10007;
    if(now <= 6)
    ret += go(k+1,6)%10007;
    if(now <= 7)
    ret += go(k+1,7)%10007;
    if(now <= 8)
    ret += go(k+1,8)%10007;
    if(now <= 9)
    ret += go(k+1,9)%10007;
    return ret%10007;
}
int main(){
    cin >> n;

    cout << go(0,0);
}