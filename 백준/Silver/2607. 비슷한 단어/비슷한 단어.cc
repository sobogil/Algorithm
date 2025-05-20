#include<bits/stdc++.h>
using namespace std;

int n,ret;
string a[101];
map<char,int> m,m2;
int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt =0;
    for(auto c : a[0]){
        cnt++;
        m[c]++;
        m2[c]++;
    }
    a[0] = "";
    for(auto s : a){
        int temp= 0;
        m=m2;
        if(s=="")continue;
        for(char c : s){
            if(m[c]) {
                temp++;
                m[c]--;
            }
        }
        int k = abs((int)s.size() -temp);
        if(temp <=cnt+1 && temp >= cnt-1 &&  k<2){
            ret++;
        }
    }
    cout << ret;
}