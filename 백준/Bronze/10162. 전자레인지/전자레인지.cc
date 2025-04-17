#include<bits/stdc++.h>
using namespace std;

int n,a[3]={300,60,10},b[3];

int main(){
    cin >>n;
    int i=0,sum=0;
    if(n%10){
        cout <<-1;return 0;
    }
    while(n){
        b[i] += n/a[i];
        n %= a[i];
        i++;
    }
    cout << b[0] <<' '<<b[1] <<' '<<b[2];
}