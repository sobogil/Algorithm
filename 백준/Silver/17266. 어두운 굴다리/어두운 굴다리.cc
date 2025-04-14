#include<bits/stdc++.h>
using namespace std;
int n,m,a[100004],ret;

bool check(int mid){
    if(a[0]-mid>0 || a[m-1]+mid < n)return false;

    for(int i=0;i<m-1;i++){
        if(a[i] +mid < a[i+1]-mid) return false;
    }
    return true;
}

int main(){
    cin >>n>>m;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    int st=0,en = n;
    while(st<=en){
        int mid = (st+en)/2;
        if(check(mid)){
            ret = mid;
            en = mid-1;
        }else{
            st = mid+1;
        }
    }
    cout <<ret;
}