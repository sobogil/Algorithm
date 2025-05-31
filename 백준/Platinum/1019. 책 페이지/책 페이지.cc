#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[10];

void solve(ll n) {
    ll pos = 1;
    while (n / pos > 0) {
        ll high = n / (pos * 10);
        ll cur = (n / pos) % 10;
        ll low = n % pos;

        for (int d = 0; d < 10; d++) {
            if (d == 0 && high == 0) continue; 

            if (d < cur) {
                if(d!=0)
                cnt[d] += (high + 1) * pos;
                if(d==0){
                    cnt[d] += (high) * pos;
                }
            } else if (d == cur) {
                cnt[d] += high * pos + (low + 1);
            } else {
                cnt[d] += high * pos;
            }
        }

        if (cur == 0) {
            cnt[0] -= pos;
        }

        pos *= 10;
    }
}

int main() {
    ll n;
    cin >> n;
    solve(n);
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
    return 0;
}