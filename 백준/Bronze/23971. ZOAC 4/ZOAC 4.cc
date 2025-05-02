#include<bits/stdc++.h>
using namespace std;

int h,n,m,w;

int main(){
    cin >>h>>w>>n>>m;

    long long ret =0,temp=1;
    ret += w/(m+1);
    ret += (w%(m+1) ? 1 : 0);
    ret *= h/(n+1) + (h%(n+1) ? 1 :0);
    cout <<ret;
}