#include<bits/stdc++.h>
using namespace std;


int n,m,t,tx,ty,y,x,ret,fret,swordret,sret;
int a[101][101],visited[101][101];
int dy[]={1,0,-1,0},dx[]={0,1,0,-1};
int main(){
    cin >> n>>m>>t;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]==2){
                ty = i; tx = j;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny<0||nx<0||ny>=n||nx>=m)continue;
            if(visited[ny][nx]||a[ny][nx]==1) continue;
            q.push({ny,nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    if(visited[n-1][m-1])
        fret = visited[n-1][m-1] -1;
    if(visited[ty][tx])
        {swordret = visited[ty][tx] - 1;
        sret = n-1-ty + m-1-tx + swordret;}
    if(fret == 0 && swordret ==0){
        cout << "Fail";
        return 0;
    }
    if(sret && fret)
        ret = min(sret,fret);

    if(ret > t){
        cout << "Fail";
        return 0;
    }else if(ret ==0){
        if(sret){
            if(sret > t){
                cout<<"Fail";
            }
            else cout << sret;
        }
        if(fret){
            if(fret > t){
                cout<<"Fail";
            }
            else cout << fret;
        }
    }
    else{
        cout << ret;
    }
    
}