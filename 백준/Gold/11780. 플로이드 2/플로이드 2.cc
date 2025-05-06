#include<bits/stdc++.h>
using namespace std;


int n,m,dist[101][101],nxt[101][101];
int INF = 987654321;

int main(){
    cin >>n>>m;
    for(int i=0;i<n;i++)
        fill(dist[i],dist[i]+n,INF);

    for(int i=0;i<n;i++){
        dist[i][i] = 0;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        a--;b--;
        dist[a][b] = min(dist[a][b],c);
        nxt[a][b] = b;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    nxt[i][j] = nxt[i][k];
                dist[i][j] = min(dist[i][k] + dist[k][j],dist[i][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF)cout << "0 ";
            else cout << dist[i][j]<<' ';
        }
        cout <<'\n';
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==0 || dist[i][j]==INF){
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st =i;
            while(st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size()<<' ';
            for(auto d : path){
                cout << d+1<<' ';
            }
            cout << '\n';
        }
    }


}