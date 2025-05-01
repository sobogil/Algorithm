#include<bits/stdc++.h>
using namespace std;


int m,s,sy,sx,d;
struct Fish{
    int y,x,d;
};
vector<Fish> fish;
struct Smell{
    int y,x,cnt=2;
};
vector<Smell> smell;
int a[5][5];
bool visited[6][6];
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,-1,-1,-1,0,1,1,1};
int sdx[]={0,-1,0,1},sdy[]={-1,0,1,0};
vector<Fish> copy_magic_start(){
    vector<Fish> result;
    for(auto & f : fish){
        result.push_back(f);
    }
    return result;
}

bool can_move(Fish &f){
    int ny = f.y + dy[f.d];
    int nx = f.x + dx[f.d];
    if(ny==sy && nx == sx)return false;
    if(ny<1||nx<1||nx>4||ny>4)return false;
    for(auto &s : smell){
        if(ny==s.y && nx==s.x)return false;
    }
    return true;
}

void fish_move() {
    for (auto &f : fish) {
        for (int i = 0; i < 8; ++i) {
            int nd = (f.d - i + 8) % 8;
            int ny = f.y + dy[nd];
            int nx = f.x + dx[nd];
            bool blocked = false;
            if (ny == sy && nx == sx) continue;
            if (ny < 1 || ny > 4 || nx < 1 || nx > 4) continue;
            for (auto &s : smell) {
                if (s.y == ny && s.x == nx) {
                    blocked = true;
                    break;
                }
            }
            if (blocked) continue;
            f.y = ny;
            f.x = nx;
            f.d = nd;
            break;
        }
    }
}

int find_fish_num(int y,int x){
    int cnt=0;
    for(auto &f: fish){
        if(f.x==x&&f.y==y)cnt++;
    }
    return cnt;
}
int max_eat;
string best_path;
void dfs(int y, int x, int depth, int sum, string path) {
    if (depth == 3) {
        if (sum > max_eat || (sum == max_eat && path < best_path)) {
            max_eat = sum;
            best_path = path;
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = y + sdy[i];
        int nx = x + sdx[i];
        if (ny < 1 || ny > 4 || nx < 1 || nx > 4) continue;
        int temp = 0;
        if (!visited[ny][nx]) {
            for (auto &f : fish) {
                if (f.y == ny && f.x == nx) {
                    temp++;
                }
            }
        }
        int flag=0;
        if(visited[ny][nx])flag=1;
        visited[ny][nx] = 1;
        dfs(ny, nx, depth + 1, sum + temp, path + to_string(i));
        if(flag){
            flag=0;continue;
        }
        visited[ny][nx] = 0;
    }
}

void make_smell(int y, int x) {
    vector<Fish> new_fish;
    bool smell_added = false;
    for (auto &f : fish) {
        if (f.y == y && f.x == x) {
            if (!smell_added) {
                smell.push_back({y, x, 2});
                smell_added = true;
            }
        } else {
            new_fish.push_back(f);
        }
    }
    fish = new_fish;
}

void shark_move() {
    max_eat = -1;
    best_path = "";
    dfs(sy, sx, 0, 0, "");
    for (char c : best_path) {
        int d = c - '0';
        sy += sdy[d];
        sx += sdx[d];

        make_smell(sy, sx); // 이 안에서 해당 칸의 물고기 삭제
    }
}

void remove_smell() {
    for (int i = smell.size() - 1; i >= 0; --i) {
    if (smell[i].cnt == 0) {
        smell.erase(smell.begin() + i);
    } else {
        smell[i].cnt--; 
    }
}
}

void copy_make_complete(vector<Fish> &fi){
    for(auto &f : fi){
        fish.push_back(f);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>m>>s;
    for(int i=0;i<m;i++){
        Fish f;
        cin >> f.y >> f.x >> d;
        d--;f.d = d;
        fish.push_back(f);
    }

    cin >> sy >> sx;

    while(s--){
        auto fishes_pos = copy_magic_start();
        fish_move();//반환값 없어도 됨
        shark_move();//함수 내부에서 가능한 경우 담아서 우선순위 고려, 물고기 냄새 남기기
        remove_smell();//물고기 냄새 삭제
        copy_make_complete(fishes_pos);//복사해서 물고기 추가
    }
    cout << fish.size();
}
