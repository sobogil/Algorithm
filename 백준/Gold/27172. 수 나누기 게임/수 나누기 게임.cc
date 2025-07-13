#include<bits/stdc++.h>
using namespace std;

int n,a[100001];
int p[1000001];
int ret[100001];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        p[a[i]]=i;
    }

    for (int i = 1; i <= n; i++) {
        int val = a[i];
        for (int j = val * 2; j <= 1000000; j += val) {
            if (p[j]) {
                ret[i]++;          // 내가 j의 약수
                ret[p[j]]--;    // j는 나의 배수
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ret[i]<<' ';
    }
}