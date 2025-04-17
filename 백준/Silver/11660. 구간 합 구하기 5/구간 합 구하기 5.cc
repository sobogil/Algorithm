#include<bits/stdc++.h>
using namespace std;

int n,m, dp[1025][1025],a[1025][1025];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >>a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for(int i=1;i<n;i++){
        dp[0][i] = dp[0][i-1] + a[0][i];
        dp[i][0] = dp[i-1][0] + a[i][0];
    }


    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }


    for(int i=0;i<m;i++){
        int x,y,nx,ny;
        cin >> x>>y >> nx>>ny;
        x--;y--;ny--;nx--;
        if(x==0 && y==0){
            cout << dp[nx][ny] << '\n';
        }else if(y==0){
            cout << dp[nx][ny] -dp[x-1][ny] << '\n';
        }else if(x==0){
            cout << dp[nx][ny] - dp[nx][y-1] << '\n';
        }else{
            cout << dp[nx][ny] - dp[nx][y-1] - dp[x-1][ny] + dp[x-1][y-1] << '\n';
        }
    }
}