#include<bits/stdc++.h>
using namespace std;

int n,a[500001],li[500001],len;
pair<int,int> p[500001];
int mxy;
int INF = 1e9;
vector<pair<int,int>> v;
map<int,int> mp;
int main(){
    fill(li,li+500001,INF);
    cin >>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >>x>>y;
        v.push_back({x,y});
        mp[y] = x;
        mxy = max(y,mxy);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int num = v[i].second;
        auto pos = lower_bound(li,li+len,num);
        if(*pos==INF)len++;
        *pos=num;
        p[i].first = pos-li;
        p[i].second = num; 
    }
    cout <<n - len<<'\n';
    stack<int> s;
    for(int i=n-1;i>=0;i--){
            
        if (p[i].first!=len-1){
            s.push(p[i].second);
        }else{len--;}
    }
    int k =s.size();
    for(int i=0;i<k;i++){
        cout << mp[s.top()]<<'\n';
        s.pop();
    }
}