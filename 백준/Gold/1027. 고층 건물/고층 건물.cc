#include<bits/stdc++.h>
using namespace std;

int n,h,ret,cnt;
int a[55];
bool solve(int i,int j){
    double f = (double)(a[j]- a[i])/(j-i);
    for(int k = min(i,j)+1; k<max(i,j);k++){
        double ex = a[i] + (k-i)*f;
        if(ex <= a[k]){
            return false;
            break;
        }
    }
    return true;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(solve(i,j))
            cnt++;
        }
        ret = max(cnt,ret);

    }
    cout << ret;
}