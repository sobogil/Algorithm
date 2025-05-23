#include<bits/stdc++.h>
using namespace std;


int n,m,mn,ret;
int a;
int board[505][505];
int main(){
    cin >>n>>m;
    for(int i=1;i<=m;i++) {
        cin >> a;
        for(int j=1;j<=a;j++){
            board[j][i] = 1;
        }   
    }

    for(int i=1;i<=n;i++){
        int flag =0;
        int le = 0;
        for(int j=1;j<=m;j++){
            if(board[i][j]==0)continue;
            if(le==0 && board[i][j])le =j;
            else if(le && board[i][j]){
                ret += j - le - 1;
                le = j;
            }
        }
    }

    cout <<ret;
}