#include<bits/stdc++.h>
using namespace std;


int t,k;
string w;

int main(){
    cin >>t;
    while(t--){
        cin >>w;
        cin >>k;

        vector<int> alpha[26];

        for(int i=0;i<w.size();i++){
            alpha[w[i]-'a'].push_back(i);
        }
        int mn = 1e9,mx = 0;
        for(int i=0;i<26;i++){
            if(alpha[i].size() < k)continue;

            for(int j=0;j<=alpha[i].size()-k;j++){
                int len = alpha[i][j+k-1] - alpha[i][j] +1;
                mn =min(mn,len);
                mx = max(mx,len);
            }

        }
                    if(mn == 1e9){
                cout << -1<<'\n';
            }else{
                cout << mn<<' '<<mx<<'\n';
            }
    }
}