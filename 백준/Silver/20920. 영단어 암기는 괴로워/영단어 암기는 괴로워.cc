#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main(){
    cin >> n>>m;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        cin >> s;
        if((int)s.size() < m)continue;
        mp[s]++;
    }
    vector<pair<int,string>> v;
    for(auto  p: mp){
        v.push_back({p.second,p.first});
    }

    sort(v.begin(),v.end(),[](pair<int,string> a, pair<int,string> b){
        if(a.first==b.first && a.second.size() != b.second.size()) return a.second.size() > b.second.size();
        if(a.first==b.first) return a.second < b.second;
        return a.first > b.first;
    });

    for(auto p : v){
        cout << p.second <<'\n';
    }
}