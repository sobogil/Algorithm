#include<bits/stdc++.h>
using namespace std;

int n,t,w,h;

int main(){
    cin >>t;
    while(t--){
        cin >>h>>w>>n;
        int a = n/h;
        int b = n%h;
        if(b==0){
            b = h;
            a--;
        }
        cout << (b)*100 + a+1<<'\n';
    }
}