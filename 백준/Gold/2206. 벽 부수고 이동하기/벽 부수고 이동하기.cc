#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001];
int visited[1001][1001][2]; 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Node {
    int y, x, broken;
};

int bfs() {
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int y = cur.y, x = cur.x, broken = cur.broken;

        if (y == n - 1 && x == m - 1) return visited[y][x][broken];

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (a[ny][nx] == 0 && visited[ny][nx][broken] == 0) {
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ny, nx, broken});
            }

            if (a[ny][nx] == 1 && broken == 0 && visited[ny][nx][1] == 0) {
                visited[ny][nx][1] = visited[y][x][0] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    return -1; // 도달 못 함
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    cout << bfs() << endl;
}