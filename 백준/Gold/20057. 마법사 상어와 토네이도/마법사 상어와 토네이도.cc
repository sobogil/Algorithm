#include<bits/stdc++.h>
using namespace std;

int n,a[505][505];

int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,-1,-1,-1,0,1,1,1};
int dir = 0;
int y,x,len=1,ret,ans;

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout <<a[i][j] <<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void magic(){
    int count =0;
    int ny = y + dy[dir]*2;
    int nx = x + dx[dir]*2;
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=a[y][x]/20;
    else a[ny][nx] += a[y][x]/20;
    count += a[y][x]/20;

    ny = y + dy[(dir+1)%8];
    nx = x + dx[(dir+1)%8];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=a[y][x]/10;
    else a[ny][nx] += a[y][x]/10;
    count += a[y][x]/10;

    ny = y + dy[(dir+2)%8];
    nx = x + dx[(dir+2)%8];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=(a[y][x]*7)/100;
    else a[ny][nx] +=(a[y][x]*7)/100;
    count += (a[y][x]*7)/100;

    ny = y + dy[(dir+2)%8]*2;
    nx = x + dx[(dir+2)%8]*2;
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=a[y][x]/50;
    else a[ny][nx] += a[y][x]/50;
    count += a[y][x]/50;

    ny = y + dy[(dir+3)%8];
    nx = x + dx[(dir+3)%8];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=(a[y][x]/100);
    else a[ny][nx] += (a[y][x]/100);
    count +=(a[y][x]/100);
    
    //중간

    ny = y + dy[(dir+7)%8];
    nx = x + dx[(dir+7)%8];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=a[y][x]/10;
    else a[ny][nx] += a[y][x]/10;
    count += a[y][x]/10;

    ny = y + dy[(dir+6)%8];
    nx = x + dx[(dir+6)%8];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=(a[y][x]*7)/100;
    else a[ny][nx] += (a[y][x]*7)/100;
    count += (a[y][x]*7)/100;

    ny = y + dy[(dir+6)%8]*2;
    nx = x + dx[(dir+6)%8]*2;
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=a[y][x]/50;
    else a[ny][nx] += a[y][x]/50;
    count += a[y][x]/50;

    ny = y + dy[(dir+5)%8];
    nx = x + dx[(dir+5)%8];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=(a[y][x]/100);
    else a[ny][nx] += (a[y][x]/100);
    count += (a[y][x]/100);

    ny = y + dy[dir];
    nx = x + dx[dir];
    if(ny<0||nx<0||ny>=n||nx>=n)ret+=a[y][x];
    else a[ny][nx] += a[y][x] - count;
    a[y][x] =0;
}

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >>a[i][j];
            ans+=a[i][j];
        }
    }
    y = n/2,x=n/2;
    int cnt =0;

    while(1){
        if(y==0&&x==0) break;
        for(int i=0;i<len;i++){
            y += dy[dir];
            x += dx[dir];
            magic();
            if(y==0&&x==0) break;
        }
        cnt++;
        if(y==0&&x==-1) x=0;

        dir = (dir+6)%8;
        
        if(cnt%2==0)len++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j])ans-=a[i][j];
        }
    }
    cout <<ans;
}