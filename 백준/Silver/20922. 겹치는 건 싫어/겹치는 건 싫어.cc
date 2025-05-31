#include<bits/stdc++.h>
using namespace std;

int n,k;
int cnt[200002],a[200002];

int main(){
    cin >> n>>k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int le=0,ri=0;
    int ret = 0;
    cnt[a[le]]=1;cnt[a[ri]]=1;
    while(1){
        if(cnt[a[ri]]<=k){
            ret = max(ret,ri-le+1);
            ri++;
            cnt[a[ri]]++;
        }else if(cnt[a[ri]]>k){
            cnt[a[le]]--;
            le++;
        }
        // cout << le <<' '<<ri <<'\n';
        if(ri>n-1)break;
    }
    cout << ret;
}