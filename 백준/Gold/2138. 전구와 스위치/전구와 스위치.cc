#include<bits/stdc++.h>
using namespace std;

int n;
string s,t;

void toggle(vector<int>&ret,int idx){
    for(int i=idx-1;i<=idx+1;i++){
        if(i<0 || i>=n)continue;
        ret[i] ^=1;
    }
}

int go(vector<int> st,vector<int>& gl, bool tf){
    int cnt = 0;
    if(tf){
        toggle(st,0);
        cnt++;
    }

    for(int i=1;i<n;i++){
        if(st[i-1] != gl[i-1]){
            toggle(st,i);
            cnt++;
        }
    }
    if(st == gl) return cnt;
    else return -1;
}

int main(){
    cin >> n >> s>>t;
    vector<int> start(n),goal(n);

    for(int i=0;i<n;i++){
        start[i] = s[i] - '0';
        goal[i] = t[i] -'0';
    }
    int res1 = go(start,goal,1);
    int res2 = go(start,goal,0);

    if (res1 == -1 && res2 == -1) cout << -1;
    else if (res1 == -1) cout << res2;
    else if (res2 == -1) cout << res1;
    else cout << min(res1, res2);
}