#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[22][22], visited[22][22];

struct Person{
    int sy,sx,dy,dx,end=0;
};

int ty,tx;
vector<Person> person;

int dy[]={0,1,0,-1}, dx[]={1,0,-1,0};

void bfs(int y,int x){
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x +dx[i];
            if(nx <=0 || ny<=0 || ny >n || nx >n)continue;
            if(a[ny][nx]==1 || visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
}

vector<Person> find_near_person(){
    int mn = 987654321;
    sort(person.begin(),person.end(),[](Person a,Person b){
        if(a.sy==b.sy) return a.sx < b.sx;
        return a.sy < b.sy;
    });
    vector<Person> temp;
    for(auto &p : person){
        if(p.end==1)continue;

        if(mn > visited[p.sy][p.sx]){
            temp.clear();
            temp.push_back(p);
            mn = visited[p.sy][p.sx];
        }
    }
    for(auto &p : person){
        if(p.sy == temp[0].sy && p.sx == temp[0].sx){
            p.end = 1;
        }
    }

    k -= visited[temp[0].sy][temp[0].sx]-1;
    ty = temp[0].sy; tx = temp[0].sx;
    return temp;
}

bool check_destination(vector<Person> &p){
    if(k - visited[p[0].dy][p[0].dx] + 1 < 0) return false;
    return true;
}

void go_destination(Person &p){
    k+= visited[p.dy][p.dx]-1;
    ty = p.dy;
    tx = p.dx;
}

int main(){
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
        }
    }

    cin >> ty>>tx;
    //택시는 3
    a[ty][tx] = 3;
    for(int i=0;i<m;i++){
        Person p;
        cin >> p.sy >> p.sx >> p.dy >> p.dx;
        person.push_back(p);
    }
    int size = person.size();
    while(size--){
        bfs(ty,tx);
        auto v = find_near_person();
        if(!visited[v[0].sy][v[0].sx]){
            cout << -1;
            return 0;
        }
        memset(visited,0,sizeof(visited));
        bfs(ty,tx);
        if(check_destination(v)){
            go_destination(v[0]);
            memset(visited,0,sizeof(visited));
        }else{
            k = -1;
            break;
        }
    }
    cout << k;
}