#include<bits/stdc++.h>
using namespace std;

int n,x,ret,cnt;
int a[250001];
vector<int> v;

int main(){
    cin >>n>>x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<x;i++){
        cnt += a[i];
    }
    ret = cnt;
    v.push_back(cnt);
    for(int i=1;i<=n-x;i++){
        int remove = i-1;
        int add = i-1+x;
        // cout << add<<' ';
        cnt -= a[remove];
        cnt += a[add];

        if(ret <= cnt){
            ret = max(ret,cnt);
            v.push_back(cnt);
        }
    }

    if(ret){
        cout << ret<<'\n';
        int k =0;
        for(auto o : v){
            if(ret == o){
                k++;
            }
        }
        cout << k;
    }else{
        cout << "SAD";
    }
}