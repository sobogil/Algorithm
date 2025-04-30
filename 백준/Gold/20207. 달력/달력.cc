#include <bits/stdc++.h>
using namespace std;

int calendar[366];

int main() {
    int n;
    cin >> n;
    while(n--) {
        int s, e;
        cin >> s >> e;
        for(int i = s; i <= e; i++) {
            calendar[i]++;
        }
    }

    int ans = 0;
    int height = 0, width = 0;
    for(int i = 1; i <= 365; i++) {
        if(calendar[i]) {
            width++;
            height = max(height, calendar[i]);
        } else if(width > 0) {
            ans += width * height;
            width = 0;
            height = 0;
        }
    }
    if(width > 0) {
        ans += width * height;
    }

    cout << ans << '\n';
}