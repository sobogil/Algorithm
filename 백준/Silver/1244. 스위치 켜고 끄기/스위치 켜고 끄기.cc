#include<bits/stdc++.h>
using namespace std;

int n,a[101],m,g,num;

int main(){
    cin >>n;
    for(int i=1;i<=n;i++)cin >>a[i];

    cin >> m;

    while(m--){
        cin >> g >> num;

        if(g==1){
            for(int i=num;i<=n;i+=num){
                a[i]^=1;
            }
        }
        else{
            int le,ri;
            le = ri = num;
            le--;ri++;
            a[num]^=1;
            while(1){
                if(le <1 || ri >n)break;
                if(a[le] != a[ri])break;
                a[le]^=1;
                a[ri]^=1;
                le--;ri++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        
        cout << a[i]<<' ';
        if(i%20==0)cout << '\n';
    }
}