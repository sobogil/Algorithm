#include<bits/stdc++.h>
using namespace std;

int x, n, a[1000004];

int main(){
    while(cin >> x){
        x *= 10000000; // x는 센티미터 단위 → 나노미터로 변환

        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];

        sort(a, a + n);
        bool found = false;

        int l = 0, r = n - 1;
        while(l < r){
            int sum = a[l] + a[r];
            if(sum == x){
                cout << "yes " << a[l] << " " << a[r] << "\n";
                found = true;
                break;
            } else if(sum < x){
                l++;
            } else{
                r--;
            }
        }

        if(!found){
            cout << "danger\n";
        }
    }
}