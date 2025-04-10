#include<bits/stdc++.h>
using namespace std;

int pool[5][5];
struct Fish{
    int X,Y,dir,died;
}a[17];
int dx[]={1,0,-1,-1,-1,0,1,1},dy[]={-1,-1,-1,0,1,1,1,0};
int first_val;
int ret,ans;

void print(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << pool[i][j]<<' ';
        }
        cout<< '\n';
    }
    cout<< '\n';
}

void move_fish(int sh_x, int sh_y){
    for(int i=1;i<17;i++){
        if(a[i].died) continue;
        int nx,ny;
        while(1){
            ny = a[i].Y + dy[a[i].dir];
            nx = a[i].X + dx[a[i].dir];
            if(ny<0||nx<0||ny>=4||nx>=4||(ny==sh_y && nx==sh_x)){
                a[i].dir = (a[i].dir + 1)%8;
                continue;
            }
            break;
        }
        if(pool[ny][nx]){
            int num = pool[ny][nx];
            pool[ny][nx] = i;
            a[num].X = a[i].X; a[num].Y = a[i].Y;
            pool[a[i].Y][a[i].X] = num;
            a[i].X = nx; a[i].Y =ny;
        }else{
            pool[a[i].Y][a[i].X] = 0;
            a[i].X = nx; a[i].Y =ny;
            pool[a[i].Y][a[i].X] = i;
        }
    }
}


void go(int sh_x, int sh_y, int sh_dir, int score){
    //물고기 이동
    ans = max(ans, score);
    int arr[5][5];
    memcpy(arr,pool,sizeof(arr));
    Fish backup_fish[17];
    memcpy(backup_fish, a, sizeof(a));
    move_fish(sh_x,sh_y);

    for (int step = 1; step < 4; step++) {
        int nx = sh_x + dx[sh_dir] * step;
        int ny = sh_y + dy[sh_dir] * step;

        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;
        if (pool[ny][nx] == 0) continue;

        int fish_num = pool[ny][nx];
        pool[ny][nx] = 0;   
        a[fish_num].died = true;

        go(nx, ny, a[fish_num].dir, score + fish_num);

        // 원상복구
        pool[ny][nx] = fish_num;
        a[fish_num].died = false;
    }

    memcpy(pool,arr,sizeof(pool));
    memcpy(a, backup_fish, sizeof(a));
}

int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int num,dir;
            cin >>num>>dir;
            pool[i][j]=num;
            a[num].Y=i;
            a[num].X=j;
            a[num].dir=dir%8;
        }
    }
    //상어 0,0등장 상어는 20으로 ㄱㄱ
    int start_fish = pool[0][0];
    a[start_fish].died = true;
    pool[0][0] = 0;
    go(0, 0, a[start_fish].dir, start_fish);
    cout << ans;
}
