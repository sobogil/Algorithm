#include<bits/stdc++.h>
using namespace std;

int n,a[50][50],m,s,d,ret,visited[50][50];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int sx,sy;
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j]<<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void blizard(){
    int ny = sy;
    int nx = sx;
    for(int i=0;i<s;i++){
        nx += dx[d];
        ny += dy[d];
        if(ny<0||nx<0||ny>=n||nx>=n)continue;
        a[ny][nx] = 0;
    }
}

int mdx[]={-1,0,1,0},mdy[]={0,1,0,-1};
void move(){
    int nx = sx;
    int ny = sy;
    int dir =0,cnt=0;
    int len = 1;
    while(!(ny==0&&nx==0)){//여기 예외처리 날 수 있음

        for(int i=0;i<len;i++){
            if(ny==0&&nx==0)break;
            // cout << ny<<' '<<nx<<'\n';
            ny += mdy[dir];
            nx += mdx[dir];
            if(a[ny][nx]==0 && i!=len-1){
                int tempy = ny + mdy[dir];
                int tempx = nx + mdx[dir];
                if (tempy >= 0 && tempy < n && tempx >= 0 && tempx < n) {
                    a[ny][nx] = a[tempy][tempx];
                    a[tempy][tempx]=0;
                }
            }
        }
        if(ny==0&&nx==0)break;
        dir = (dir+1)%4;
        if(a[ny][nx]==0){
            int tempy = ny + mdy[dir];
            int tempx = nx + mdx[dir];
            if (tempy >= 0 && tempy < n && tempx >= 0 && tempx < n) {
                a[ny][nx] = a[tempy][tempx];
                a[tempy][tempx]=0;
            }
        }
        cnt++;
        if(cnt%2==0)len++;
    }
    // print();
}

bool bfs(int y,int x,int remain,int cnt,int dir,int len){
    visited[y][x]=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    int ny,nx;
    if(remain==0){
        cnt++;
        if(cnt%2==0)len++;
        dir=(dir+1)%4;
        remain=len;
    }
    while(q.size()){
        tie(y,x) = q.front();q.pop();
        for(int i=0;i<remain;i++){
            ny = y + mdy[dir];
            nx = x + mdx[dir];
            // cout << ny<<' '<<nx<<' '<<dir<<' '<<len<<'\n';

            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(a[ny][nx] != a[y][x]){
                if(visited[y][x]>=4){return true;}
                else return false;
            }
            visited[ny][nx] = visited[y][x]+1;
            
            y =ny;x=nx;
        }
        q.push({ny,nx});
        cnt++;
        if(cnt%2==0)len++;
        remain = len;
        dir = (dir+1)%4;
    }
}

vector<pair<int,int>> find_four(){
    int nx = sx;
    int ny = sy;
    int dir =0,cnt=0;
    int len = 1;
    int flag =0;
    int x = nx,y=nx;
    visited[ny][nx] = 1;
    vector<pair<int,int>> result;
    while((ny==sy&&nx==sx) || a[ny][nx]){//여기 예외처리 날 수 있음
        for(int i=0;i<len;i++){
            x=nx,y=ny;
            ny += mdy[dir];
            nx += mdx[dir];
            // cout << visited[ny][nx];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(a[ny][nx]==0)break;
            if(visited[ny][nx] && flag==1){
                result.push_back({ny,nx});
                continue;
            }
            // cout <<"PP";
            if(visited[ny][nx])continue;
            // cout <<"go";
            if(a[ny][nx]!=a[ny-mdy[dir]][nx-mdx[dir]]){
                flag=0;
            }
            
            if(bfs(ny,nx,len-i-1,cnt,dir,len)){
                result.push_back({ny,nx});
                flag=1;
            }
        }
        dir = (dir+1)%4;
        cnt++;
        if(cnt%2==0)len++;
    }
    return result;
}
int boom1,boom2,boom3;
void boom(vector<pair<int,int>> &v){
    for(auto &p: v){
        if(a[p.first][p.second]==1){
            boom1++;
        }else if(a[p.first][p.second]==2)boom2++;
        else if(a[p.first][p.second]==3)boom3++;
        a[p.first][p.second] = 0;
    }
}

void get_score(){
    ret +=1*boom1;
    ret +=2*boom2;
    ret +=3*boom3;
    boom1=0,boom2=0,boom3=0;
}

void change(){
    // 리스트로 전부 넣어놓고 전부 0으로 만들고 새로 채워 넣기;
    int nx = sx;
    int ny = sy;
    int dir =0,cnt=0;
    int len = 1;
    int ball_count=0,ok=0;
    int x=nx,y=ny;
    vector<int> result;
    while(1){
        for(int i=0;i<len;i++){
            // cout << y << ' '<<x<<'\n';
            ny = y + mdy[dir];
            nx = x + mdx[dir];
            // cout << ny<<' '<<nx<<'\n';
            // cout << a[ny][nx] << 'T' << a[y][x]<<'\n';
            if(ny <0 || nx<0 || ny>=n || nx>=n)continue;
            if(!(y==sy&&x==sx) && a[ny][nx]!=a[y][x]){
                // cout << "real";
                result.push_back(ball_count);
                result.push_back(a[y][x]);
                ball_count=0;
            }
            if(a[ny][nx]==0 || result.size()>=n*n){ok=1;break;}
            ball_count++;
            y=ny;x=nx;
        }
        if(ok)break;
        dir=(dir+1)%4;
        cnt++;
        if(cnt%2==0)len++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)a[i][j]=0;
    }
    //update
    nx = sx-1;
    ny = sy;
    dir =1,cnt=1;
    len = 1;
    int temp = len;
    x=nx,y=ny;
    for(auto &i:result){
        a[y][x] = i;
        ny = y+mdy[dir];
        nx = x +mdx[dir];
        len--;
        y = ny;
        x = nx;
        if(y<0 || y>=n||x<0||x>=n)break;
        if(len>0)continue;

        dir=(dir+1)%4;
        cnt++;
        if(cnt%2==0)temp++;
        len = temp;
    }
}

int main(){
    cin >>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    sy = n/2,sx=n/2;
    while(m--){
        cin >> d>>s;d--;
        // print();
        blizard();
        // print();
        for(int i=0;i<s;i++)move();
        // print();
        while(1){
            auto v = find_four();
            // for(auto p : v){
            //     cout << 'f';
            //     cout << p.first<<' '<< p.second<<'\n';
            // }
            if(!v.size())break;
            boom(v);//폭발할때 몇번 구슬이 몇개 폭발했는지 카운트해야함
            // print();
            for(int i=0;i<v.size();i++)move();
            // cout << "IMP"<<ret<<'\n';
            get_score();
            
            memset(visited,0,sizeof(visited));
        }
        
        memset(visited,0,sizeof(visited));
        // print();
        change();
        // print();

    }
    // print();
    cout << ret;
}