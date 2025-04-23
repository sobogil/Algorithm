#include<bits/stdc++.h>
using namespace std;

int n;
string s;
string a[11];
map<char,int> mp, cnt_map;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int temp =1;
        cin >> a[i];
        for(int j=a[i].size()-1; j>=0;j--){
            temp*=10;
            mp[a[i][j]]+= temp;
        }
    }
    int sum =0;
    vector<pair<char,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),[](pair<char,int> a,pair<char,int> b){
        return a.second > b.second;
    });
    int cnt = 9;
    for(auto &p : v){
        cnt_map[p.first] = cnt;
        cnt--;
    }

    for(int i=0;i<n;i++){
        int size = a[i].size();
        for(auto &s : a[i]){
            int ret =1;
            size--;
            for(int j=0;j<size;j++){
                ret*=10;
            }
            sum+=cnt_map[s]*ret;
        }
    }
    cout << sum;
}