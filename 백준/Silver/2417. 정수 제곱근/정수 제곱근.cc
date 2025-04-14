#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll st = 1, en = n, ret = 0;
    while (st <= en) {
        ll mid = (st + en) / 2;
        if (mid > 1e20 || mid > n / mid) {
            en = mid - 1;
        } else {
            ret = mid;

            st = mid + 1;
        }
    }
    if(ret*ret == n) cout << ret;
    else{
    cout << ret+1 << "\n";}
    return 0;
}