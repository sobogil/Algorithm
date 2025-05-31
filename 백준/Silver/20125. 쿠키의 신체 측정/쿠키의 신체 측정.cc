#include<bits/stdc++.h>
using namespace std;

int n;
char a[1001][1001],ok;

int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
pair<int,int> p;
bool find(int y,int x){
    if(a[y][x]=='_')return false;
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx =  x  +dx[i];
        int ny =  y +dy[i];
        if(nx<0||ny<0||ny>=n||nx>=n)return false;
        if(a[ny][nx]=='*')cnt++;
    }
    if(cnt==4){
        return true;
    }
    return false;
}


int main(){
    cin >>n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(find(i,j)){
                ok=1;
                p.first = i;
                p.second = j;
                break;
            }
        }
        if(ok)break;
    }

    cout << p.first+1<<' '<<p.second+1<<'\n';
    int y = p.first;
    int x = p.second;
    int cnt =0;
    while(1){
        int nx = x + dx[2];
        int ny = y + dy[2];
        if(nx<0||ny<0||ny>=n||nx>=n)break;
        if(a[ny][nx]!='*')break;
        y=ny;
        x= nx;
        cnt++;
    }
    cout <<cnt <<' ';
    y = p.first;
    x = p.second;
    cnt=0;
    while(1){
        int nx = x + dx[0];
        int ny = y + dy[0];
        if(nx<0||ny<0||ny>=n||nx>=n)break;
        if(a[ny][nx]!='*')break;
        cnt++;
        y=ny;
        x= nx;
    }
    cout <<cnt <<' ';
    y = p.first;
    x = p.second;
    cnt=0;
    while(1){
        int nx = x + dx[1];
        int ny = y + dy[1];
        if(nx<0||ny<0||ny>=n||nx>=n)break;
        if(a[ny][nx]!='*')break;
        cnt++;
        y=ny;
        x= nx;
    }
    cout <<cnt <<' ';

    int ley = y+1;
    int lex = x-1;
    int riy= y+1;
    int rix=x+1;

    cnt=1;
    while(1){
        int nx = lex + dx[1];
        int ny = ley + dy[1];
        if(nx<0||ny<0||ny>=n||nx>=n)break;
        if(a[ny][nx]!='*')break;
        cnt++;
        ley=ny;
        lex= nx;
    }
    cout <<cnt <<' ';

    cnt=1;
    while(1){
        int nx = rix + dx[1];
        int ny = riy + dy[1];
        if(nx<0||ny<0||ny>=n||nx>=n)break;
        if(a[ny][nx]!='*')break;
        cnt++;
        riy=ny;
        rix= nx;
    }
    cout <<cnt <<' ';
}