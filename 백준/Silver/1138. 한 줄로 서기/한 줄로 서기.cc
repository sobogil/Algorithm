#include<bits/stdc++.h>
using namespace std;

int n,a[11],ret[11];

int main(){
    cin >> n;

    vector<int> info(n+1);
    for (int i = 0; i < n; ++i)
        cin >> info[i];

    vector<int> line(n);

    for(int i=0;i<n;i++){
        int temp = info[i];
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(0 == line[j]){
                if(cnt == temp){
                    line[j] = i+1;
                    break;
                }
                cnt++;
            }
        }
    }
    for(auto x : line){
        cout << x <<' ';
    }
}