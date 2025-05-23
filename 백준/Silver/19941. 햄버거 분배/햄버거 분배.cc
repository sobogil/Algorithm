#include<bits/stdc++.h>
using namespace std;

int n,k,ret,cnt[20002];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>n>>k;
    cin >> s;
    char c = s[0];
    for(int i=0;i<n;i++){
        if(s[i] != c)continue;
        for(int j=-k;j<=k;j++){
            if(i+j>=n || i+j <0)continue;
            if(cnt[i+j])continue;
            if(s[i+j] == s[i]) continue;
            cnt[i+j] = 1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(cnt[i])ret++;
    }
    cout << ret;
}