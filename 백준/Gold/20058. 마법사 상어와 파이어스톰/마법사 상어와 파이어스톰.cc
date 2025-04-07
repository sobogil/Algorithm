#include<bits/stdc++.h>
using namespace std;

int n,q,a[70][70],l,k=1,board=1,visited[70][70];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

void _rotate(int y,int x){
    vector<vector<int>> temp;
    temp.clear();
    for(int i=0;i<k;i++){
        vector<int> row;
        for(int j=0;j<k;j++){
            row.push_back(a[i+y][j+x]);
        }
        temp.push_back(row);
    }
    // vector<vector<int>> rotated(temp.size(),vector<int>(temp[0].size()));
    vector<vector<int>> rotated = temp;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            rotated[j][k-i-1] = temp[i][j];
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            a[i+y][j+x] = rotated[i][j];
        }
    }
}

int find_ice(int y,int x){
    int ret=0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||ny>=board||nx>=board)continue;
        if(a[ny][nx])ret++;
    }
    return ret;
}

void remove_ice(){
    int temp[70][70];
    memcpy(temp,a,sizeof(temp));
    for(int i=0;i<board;i++){
        for(int j=0;j<board;j++){
            int cnt = find_ice(i,j);
            if(cnt < 3 && a[i][j] > 0){
                temp[i][j]--;
            }
        }
    }
    memcpy(a,temp,sizeof(a));
}

int bfs(int y,int x){
    visited[y][x] =1;
    queue<pair<int,int>> q;
    int cnt=1;
    q.push({y,x});
    while(q.size()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0||ny<0||ny>=board||nx>=board || visited[ny][nx])continue;
            if(a[ny][nx]!=0){
                visited[ny][nx] = visited[cy][cx] +1;
                cnt++;
                q.push({ny,nx});
            }
        }
    }
    return cnt;
}

int main(){
    cin >>n>>q;
    for(int i=0;i<n;i++)board *= 2;
    for(int i=0;i<board;i++){
        for(int j=0;j<board;j++){
            cin >>a[i][j];
        }
    }


    while(q--){
        cin >>l;
        k=1;
        for(int i=0;i<l;i++){
            k*=2;
        }
        for(int i=0;i<board;i+=k){
            for(int j=0;j<board; j+=k){
                _rotate(i,j);
            }
        }

        remove_ice();
    }

    int sum=0;
    for(int i=0;i<board;i++){
        for(int j=0;j<board;j++){
            if(a[i][j]<=0)continue;
            sum += a[i][j];
        }
    }
    int max_count=0;
    for(int i=0;i<board;i++){
        for(int j=0;j<board;j++){
            if(a[i][j]<=0)continue;
            max_count = max(max_count,bfs(i,j));
        }
    }
    
    cout << sum <<'\n'<<max_count;
}