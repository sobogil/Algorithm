#include<bits/stdc++.h>
using namespace std;

long long a,b;

int main(){
    cin >>a>>b;
    long long temp = 1;
    while(a < b){
        if(b%2 && b%10!=1)break;
        if(b%2)b/=10;
        else b/=2;
        temp++;
    }
    if(a==b)cout << temp;
    else cout << -1;
}