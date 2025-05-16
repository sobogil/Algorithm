#include<bits/stdc++.h>
using namespace std;
string s[20002];
int main(){
    int n,mx;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    vector<pair<string, string>> v;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j==i)continue;
            int cnt=0;
            while(1){
                if(cnt >= max(s[i].size(),s[j].size()))break;
                if(s[i][cnt] == s[j][cnt]){
                    cnt++;
                }else{
                    if(cnt > mx){
                        mx = cnt;
                        v.clear();
                        v.push_back({s[i],s[j]});
                    }
                    break;
                }
            }
        }
    }

    cout << v[0].first <<'\n' << v[0].second;
}