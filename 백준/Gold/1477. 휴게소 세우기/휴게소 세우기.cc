#include<bits/stdc++.h>
using namespace std;

int n,m,l;
int ret;
vector<int> a;
int main(){
    cin >>n>>m>>l;
    int temp = 0;
    a.push_back(0);
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        a.push_back(k);
    }
    a.push_back(l);
    sort(a.begin(),a.end());
    int le = 1; int ri = l;
    while(le <= ri){
        int mid = (le + ri)/2;
        int c =0;
        for(int i=1;i<a.size();i++){
            int d = a[i] - a[i-1];
            c += (d-1)/mid;
        }

        if(c > m){
            le = mid+1;
        }else{
            ret = mid;
            ri = mid-1;
        }
    }

    cout << ret;
}