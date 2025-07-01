#include<bits/stdc++.h>
using namespace std;

int t;
int n,m;
char a[105][105];
int visited[105][105];
int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
map<char,int> mp;
int ret;

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
}
int bfs(){
    int get = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y +dy[i];
            int nx = x +dx[i];
            if(nx<0||ny<0||nx>m+1||ny>n+1)continue;
            if(visited[ny][nx] || a[ny][nx] =='*')continue;
            if(65 <= a[ny][nx] && a[ny][nx] <=90){
                if(mp[a[ny][nx]]!=1)continue;
                // cout << a[ny][nx];
                q.push({ny,nx});
                a[ny][nx]='.';
                visited[ny][nx] = visited[y][x] + 1;
            }else if(97 <= a[ny][nx] && a[ny][nx] <=122){
                mp[toupper(a[ny][nx])]=1;
                a[ny][nx] = '.';
                q.push({ny,nx});
                visited[ny][nx] = visited[y][x] + 1;
                get++;
            }
            if(a[ny][nx]=='$'){
                a[ny][nx]='.';
                ret++;
                q.push({ny,nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
            if(a[ny][nx]=='.'||!a[ny][nx]){
                q.push({ny,nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    return get;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>t;
    while(t--){
        ret = 0;
        memset(visited,0,sizeof(visited));
        memset(a,0,sizeof(a));
        mp.clear();
        cin >>n>>m;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            for(int j=1;j<=m;j++){
                a[i][j] = s[j-1];
            }
        }

        string s;
        cin >> s;
        if(s!="0"){
        for(auto c : s){
            char temp = (char)toupper(c);
            mp[temp] = 1;
        }
        }
        while(1){
            int val = bfs();
            memset(visited,0,sizeof(visited));
            //print();
            if(val==0)break;
        }
        cout << ret<<'\n';
    }
}