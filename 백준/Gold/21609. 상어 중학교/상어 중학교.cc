#include<bits/stdc++.h>
using namespace std;

int n,m,a[22][22],visited[22][22],score;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j]<<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

pair<int,int> bfs(int y,int x, int val){
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    int cnt = 1;
    int cnt_rainbow = 0;
    while(q.size()){
        tie(y,x) = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(visited[ny][nx])continue;
            if(a[ny][nx]==val || a[ny][nx]==0){
                cnt++;
                if(a[ny][nx]==0){
                    cnt_rainbow++;
                }
                visited[ny][nx]=1;
                q.push({ny,nx});
            }
        }
    }
    return {cnt, cnt_rainbow};
}

vector<pair<int,int>> find_group(){
    int ret = 0;
    int rain = 0;
    vector<pair<int,int>> result(1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==10)continue;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(!a[i][j]&&visited[i][j])visited[i][j]=0;
                }
            }
            if(a[i][j]<=-1)continue;

            if(a[i][j]==0)continue;
            if(visited[i][j])continue;
            pair<int,int> temp = bfs(i,j,a[i][j]);
            
            if(ret < temp.first && temp.first > 1){
                
                result[0].first = i;
                result[0].second = j;
                rain = temp.second;
                ret = temp.first;
            } else if(ret == temp.first &&  temp.second > rain){
                result[0].first = i;
                result[0].second = j;
                rain = temp.second;
            }
            else if(ret == temp.first &&  temp.second == rain){
                // cout<<"\n" << i << ' ' << j<<' '<<temp.first<<"\n";
                result[0].first = i;
                result[0].second = j;
            }
        }
    }
    memset(visited,0,sizeof(visited));
    return result;
}

void remove_group(pair<int,int> &p){
    int y = p.first;int x= p.second;
    int val = a[y][x];
    a[y][x] = 10;
    int ret = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x) = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = y +dy[i];
            int nx = x  + dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(visited[ny][nx])continue;
            if(a[ny][nx]==val || a[ny][nx]==0){
                a[ny][nx] = 10;
                visited[ny][nx]=1;
                ret++;
                q.push({ny,nx});
            }
        }
    }
    score += ret*ret;
    memset(visited,0,sizeof(visited));
    return ;
}

void gravity(){
    for(int k =0;k<n;k++){
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(a[i][j]<=-1)continue;
                if(a[i][j]==10)continue;
                if(a[i+1][j] == 10){
                    a[i+1][j] = a[i][j];
                    a[i][j] =10;
                }
            }
        }
    }
}

void _rotate270(){
    int temp[22][22]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[n-j-1][i] = a[i][j];
        }
    }
    memcpy(a,temp,sizeof(a));
}

int main(){
    cin >> n >>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    while(1){
        auto v = find_group();
        // cout << v[0].first << ' '<<v[0].second;
        if(a[v[0].first][v[0].second]==10 ||a[v[0].first][v[0].second]<=0)break;
        auto p = bfs(v[0].first , v[0].second, a[v[0].first][v[0].second]);
        if(p.first <2 )break;
        memset(visited,0,sizeof(visited));
        // print();
        remove_group(v[0]);
        // cout<<'\n'<<score<<'\n';
        // print();
        gravity();
        // print();
        _rotate270();
        // print();
        gravity();
        // print();
    }
    cout << score;
}