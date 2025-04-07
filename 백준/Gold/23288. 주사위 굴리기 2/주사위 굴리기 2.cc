#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[22][22],visited[22][22],ret;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int dice[] = {1,6,3,4,2,5}; //위,아래,동,서,남,북
int y,x,dir;
int bfs(){
    visited[y][x]=1;
    int cnt =1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        int tx,ty;
        tie(ty,tx) = q.front();q.pop();

        for(int i=0;i<4;i++){
            int ny = ty + dy[i];
            int nx = tx + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m)continue;
            if(a[ny][nx]!=a[ty][tx])continue;
            if(visited[ny][nx])continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
            cnt++;
        }
    }
    return cnt;
}

int get_score(){
    int cnt = bfs();
    memset(visited,0,sizeof(visited));
    return cnt*a[y][x];
}

void move(){
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny<0 || nx<0 || ny>=n || nx>=m){
        dir = (dir+2)%4;
        ny = y + dy[dir];
        nx = x + dx[dir];
    }
    y=ny; x= nx;
    int temp = dice[0];
    if(dir == 0){
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }else if(dir == 1){
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }else if(dir == 2){
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }else if(dir == 3){
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
}

void _rotate(){
    if(dice[1] > a[y][x]) dir = (dir+1)%4;
    else if(dice[1] < a[y][x]) dir = (dir+3)%4;
}

int main(){
    cin >> n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>a[i][j];
        }
    }


    while(k--){
        move();
        ret += get_score();
        _rotate();
    }

    cout <<ret;
}