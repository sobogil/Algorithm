#include<bits/stdc++.h>
using namespace std;

int n;

int main(){

    cin >> n;
    int temp[] = {500,100,50,10,5,1};
    int ret= 1000-n;
    int ans=0;
    int i=0;
    while(ret){
        ans += ret/temp[i];
        ret %= temp[i];
        i++;
    }
    cout <<ans;
}