#include<bits/stdc++.h>
using namespace std;


int a[20][20];
int dx[] = {1,1,0,1}, dy[] = {0,1,1,-1};

bool check(int y, int x, int dir){
    int color = a[y][x];
    int cnt = 1;

    int ny = y, nx = x;
    for(int i = 0; i < 4; i++){ 
        ny += dy[dir];
        nx += dx[dir];
        if(ny < 0 || nx < 0 || ny >= 19 || nx >= 19) break;
        if(a[ny][nx] != color) break;
        cnt++;
    }

    int py = y - dy[dir], px = x - dx[dir];
    if(py >= 0 && px >= 0 && py < 19 && px < 19 && a[py][px] == color)
        return false; 

    ny += dy[dir];
    nx += dx[dir];
    if(ny >= 0 && nx >= 0 && ny < 19 && nx < 19 && a[ny][nx] == color)
        return false;

    return cnt == 5;
}

int main(){
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++)
            cin >> a[i][j];

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if(a[i][j] == 0) continue;
            for(int dir = 0; dir < 4; dir++){
                if(check(i,j,dir)){
                    cout << a[i][j] << '\n';
                    cout << i+1 << ' ' << j+1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 0;
}