#include<bits/stdc++.h>
using namespace std;


int n;

int main(){
    cin >> n;
    stack<pair<int,int>> s;
    vector<int> h(n+1);
    vector<int> ret(n+1);

    for(int i=1;i<=n;i++){
        cin >> h[i];
        while(s.size() && s.top().first < h[i]){
            s.pop();
        }
        if(s.size()){
            ret[i] = s.top().second;
        }else{
            ret[i] = 0;
        }

        s.push({h[i],i});
    }
    for(int i=1;i<=n;i++){
        cout << ret[i]<<' ';
    }
}