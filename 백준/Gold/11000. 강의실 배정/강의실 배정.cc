#include<bits/stdc++.h>
using namespace std;

int n,s,t;
vector<pair<int,int>> v;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s>>t;
        v.push_back({s,t});
    }
    sort(v.begin(),v.end());
    priority_queue<int, vector<int>,greater<int>> pq;
    pq.push(v[0].second);
    for(int i=1;i<v.size();i++){
        int st = v[i].first;
        int en = v[i].second;
        if(!pq.empty() &&pq.top() <= st) pq.pop();

        pq.push(en);
    }
    cout << pq.size();
}