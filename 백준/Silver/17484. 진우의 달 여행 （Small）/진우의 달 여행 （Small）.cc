#include<bits/stdc++.h>
using namespace std;

int n,m,a[10][10],dp[10][10][4];
const int INF = 987654321;
int ret =INF;
int go(int y,int x,int dir){
    if(y==n){
        return 0;
    }
    if(x<0||x>=m)return INF;
    int &ret = dp[y][x][dir];
    if(ret!=INF)return ret;

    if(dir==0){
        ret = min(ret, go(y+1,x-1,1)+a[y][x]);
        ret = min(ret, go(y+1,x+1,3)+a[y][x]);
        ret = min(ret, go(y+1,x,2)+a[y][x]);
    }else if(dir==1){
        ret = min(ret, go(y+1,x+1,3)+a[y][x]);
        ret = min(ret, go(y+1,x,2)+a[y][x]);
    }else if(dir==2){
        ret = min(ret, go(y+1,x+1,3)+a[y][x]);
        ret = min(ret, go(y+1,x-1,1)+a[y][x]);
    }else if(dir==3){
        ret = min(ret, go(y+1,x-1,1)+a[y][x]);
        ret = min(ret, go(y+1,x,2)+a[y][x]);
    }

    return ret;
}

int main(){
    cin >>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fill(dp[i][j], dp[i][j]+5,INF);
        }
    }

    for(int i=0;i<m;i++){
        ret = min(ret, go(0,i,0));
    }
    cout << ret;
}