#include<bits/stdc++.h>
using namespace std;


int n,board[10][10],ret1,ret2,d1[20],d2[22];
int dy[]={-1,-1,1,1},dx[]={-1,1,1,-1};


void go(int y,int x,int cnt,int color,int &ret){
    if(x>=n){
        y++;
        x = (x%2==0) ? 1:0;
    }

    if(y>=n){
        ret = max(cnt,ret);
        return ;
    }


    if(board[y][x]==1 && !d1[y+x] && !d2[y-x+n]){
        d1[y+x] = d2[y-x+n] = 1;
        go(y,x+2,cnt+1,color,ret);
        d1[y+x] = d2[y-x+n] = 0;
    }
    go(y,x+2,cnt,color,ret);
    
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >>board[i][j];
        }
    }

    go(0,0,0,0,ret1);
    go(0,1,0,1,ret2);
    cout << ret1+ret2;
}