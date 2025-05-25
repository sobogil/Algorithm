#include<bits/stdc++.h>
using namespace std;
int n,a[202];
int lis[202];
int len;
int main(){
    cin >>n;
    for(int i=0;i<n;i++)cin >> a[i];

    for(int i=0;i<n;i++){
        int num = a[i];
        auto pos = lower_bound(lis,lis + len,num);
        if(*pos ==0){
            len++;
            *pos = num;
        }else{
            *pos = num;
        }
    }
    cout << n- len;
}