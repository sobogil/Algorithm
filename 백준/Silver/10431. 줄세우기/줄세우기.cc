#include<bits/stdc++.h>
using namespace std;

int t,n,a[22],cnt;

int main(){
    cin >>t;
    while(t--){
        cin >>n;
        for(int i=0;i<20;i++)cin >>a[i];
        cnt=0;
        for(int i=0;i<20;i++){
            for(int j=0;j<19;j++){
                if(a[j] > a[j+1]){
                    swap(a[j],a[j+1]);
                    cnt++;
                }
            }
        }

        cout << n << ' '<< cnt<<'\n';
    }
}