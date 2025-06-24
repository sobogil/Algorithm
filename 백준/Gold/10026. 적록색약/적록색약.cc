#include<bits/stdc++.h>
using namespace std;

int n;
char a[101][101];
string s;
int st,en;
int visited[101][101];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(int y,int x){
    visited[y][x]= 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny<0||nx<0||ny>=n||nx>=n)continue;
        if(visited[ny][nx])continue;
        if(a[y][x] != a[ny][nx])continue;
        dfs(ny,nx);
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j])continue;
            dfs(i,j);
            st++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='G'){
                a[i][j]='R';
            }
        }
    }
    memset(visited,0,sizeof(visited));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j])continue;
            dfs(i,j);
            en++;
        }
    }

    cout << st <<' '<< en;
}