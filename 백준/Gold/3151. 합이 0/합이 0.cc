#include<bits/stdc++.h>
using namespace std;

int n,a[20004];
typedef long long ll;
ll ret;

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        int st =i+1,en = n-1;
        while(st<en){
            int mid = a[st] + a[en] + a[i];
            if(mid ==0){
                if (a[st] == a[en]) {
                    int cnt = en - st + 1;
                    ret += 1LL * cnt * (cnt - 1) / 2;
                    break;
                } else {
                    int lc = 1, rc = 1;
                    while (st + 1 < en && a[st] == a[st + 1]) {
                        lc++;
                        st++;
                    }
                    while (en - 1 > st && a[en] == a[en - 1]) {
                        rc++;
                        en--;
                    }
                    ret += 1LL * lc * rc;
                    st++;
                    en--;
                }
            }
            else if(mid<0) st++;
            else en--;
        }
    }
    cout << ret;
}