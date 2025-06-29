#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
};
bool operator<(Point a, Point b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool operator>(Point a, Point b) {
    return b < a;
}
int ccw(Point a, Point b, Point c) {
    ll val = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
    if (val > 0) return 1;    // 반시계
    else if (val < 0) return -1; // 시계
    else return 0; // 일직선
}

bool isCross(Point a, Point b, Point c, Point d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return !(b < c || d < a);  // 겹침 여부 확인
    }

    return ab <= 0 && cd <= 0;
}



int main() {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    cout << isCross(a, b, c, d);
}