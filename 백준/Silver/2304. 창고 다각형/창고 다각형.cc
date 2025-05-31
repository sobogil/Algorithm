#include<bits/stdc++.h>
using namespace std;

int n,mx,ret;
int a[1001][1001];

int main(){
    cin >>n;
    int MAX_X=0,MAX_Y=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x>>y;
        // y--;x--;
        for(int j=0;j<y;j++){
            a[j][x] = 1;
        }
        MAX_Y = max(MAX_Y,y);
        MAX_X = max(MAX_X,x);
    }
    
    for(int i=0;i<=MAX_Y;i++){
        int le=0,ri=0,flag=0;
        for(int j=0;j<=MAX_X;j++){
            if(a[i][j]){
                if(!flag){
                    le=j;
                    flag=1;
                }else{
                    ri=j;
                }
            }
        }
        if(ri==0 && le){
            ret++;
        }else if(ri&&le){
            ret += ri-le+1;
        }
        // cout << ret<<' ';
    }
    cout << ret;
}