#include<bits/stdc++.h>
using namespace std;

int t, n, ret;
vector<pair<int,int>> v;

int main(){
    cin >>t;

    while(t--){
        ret = 1;
        cin >> n;
        v.clear();
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int mx = v[0].second;
        for(int i=1;i<n;i++){
            mx = min(mx, v[i].second);
            if(mx == v[i].second)ret++;
        }
        cout << ret << '\n';

    }
}