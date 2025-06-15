#include<bits/stdc++.h>
using namespace std;

int n,t,a[1001];
vector<int> v[1001];
map<int,int> m;
vector<pair<int,int>> v2,v3,v4;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        
        v2.clear();v3.clear();
        m.clear();
        int mx = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            m[a[i]]++;
            mx = max(a[i],mx);
        }
        int j = 1;
        for(int i=1;i<=n;i++){
            if(m[a[i]] != 6)continue;
            v[a[i]].push_back(j);
            j++;
        }

        for(int i=1;i<=mx;i++){
            if(v[i].size()!=6)continue;
            int temp =0;
            for(int k=0;k<4;k++){
                temp += v[i][k]; 
            }
            v2.push_back({temp,i});
        }
        int val =987654321;
        for(int i=0;i<v2.size();i++){
            val = min(v2[i].first,val);
        }
        for(int i=0;i<v2.size();i++){
            // cout << v2[i].second;
            if(val == v2[i].first)v3.push_back({val,v2[i].second});
        }
        if(v3.size()==1){
            // cout <<"gg";
            cout << v3[0].second<<'\n';
        }
        else if(v3.size()>1){
            for(auto &c : v3){
                c.first += v[c.second][4];
            }
            sort(v3.begin(),v3.end());
            cout << v3[0].second<<'\n';
        }

        for(int i=1;i<=mx;i++)v[i].clear();
    }
}