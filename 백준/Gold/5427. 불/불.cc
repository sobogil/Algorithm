#include<bits/stdc++.h>
using namespace std;

int t,n,m;
char a[1001][1001];

int visited[1001][1001];
int dy[] = {0,1,0,-1},dx[]={1,0,-1,0};

int main(){
    cin >>t;
    
    while(t--){
        int flag =0;
        int mey,mex;
        cin >>m>>n;
        queue<pair<pair<int,int>,char>> q;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >>a[i][j];
                if(a[i][j]=='*'){
                    q.push({{i,j},'*'});
                }
                if(a[i][j] == '@'){
                    mey=i,mex=j;
                }
            }
        }
        q.push({{mey,mex},'@'});
        while(q.size()){
            int y,x,c;
            pair<int,int> point;
            tie(point,c) = q.front(); q.pop();
            y = point.first;
            x = point.second;
            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m){
                    if(c == '*')continue;
                    cout << visited[y][x] +1<<'\n';
                    flag = 1;
                    break;
                }

                if(c=='@'){
                    if(a[ny][nx]=='*' || a[ny][nx]=='#')continue;
                    if(visited[ny][nx])continue;
                    visited[ny][nx] = visited[y][x] +1;
                    q.push({{ny,nx},'@'});
                }
                if(c=='*'){
                    if(a[ny][nx]=='*' || a[ny][nx]=='#')continue;
                    a[ny][nx] = '*';
                    q.push({{ny,nx},'*'});
                }

            }
            if(flag)break;
        }
        if(!flag)
        cout <<"IMPOSSIBLE"<<'\n';
    }
}