#include<bits/stdc++.h>
using namespace std;


int t,n,sx,sy,ex,ey,visited[303][303],a[303][303],y,x;
int dy[]={-1,-2,-2,-1,1,2,2,1},dx[]={-2,-1,1,2,2,1,-1,-2};

int main(){
    cin >>t;
    while(t--){
        cin >>n;
        cin >> sy>>sx;
        cin >> ey>>ex;
        queue<pair<int,int>> q;
        q.push({sy,sx});
        visited[sy][sx] = 1;
        while(q.size()){
            tie(y,x) = q.front();q.pop();
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;
                if(visited[ny][nx])continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
        cout << visited[ey][ex]-1 << '\n';
        memset(visited,0,sizeof(visited));
    }
}