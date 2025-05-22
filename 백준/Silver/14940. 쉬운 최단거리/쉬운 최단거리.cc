#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001],visited[1001][1001];
int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
int y,x;

void bfs(int y,int x){
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});

    while(q.size()){
        tie(y,x) = q.front();q.pop();

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m)continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] == 0) continue;
            q.push({ny,nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}

int main(){
    cin >>n>>m;

    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]==2){
                y=i;x=j;
            }
        }
    }

    bfs(y,x);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && a[i][j]==0)
            cout << visited[i][j] << ' ';
            else if(!visited[i][j] && a[i][j]==1)
            cout << visited[i][j] - 1<<' ';
            else
            cout << visited[i][j] - 1<<' ';
        }
        cout <<'\n';
    }
}