#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a,b,l,cnt;
int shoot[100004], animal;
vector<pair<int,int>> v;
int main(){
    cin >> m>>n>>l;
    for(int i=0;i<m;i++) cin >> shoot[i];
    sort(shoot,shoot+m);
    for(int i=0;i<n;i++){
        cin >> a>>b;

        if(b>l)continue;
        int le = a - (l-b);
        int ri = a + (l-b);

        if(lower_bound(shoot,shoot+m,le) != shoot+m &&
        *lower_bound(shoot,shoot+m,le) <= ri)cnt++;
    }
    cout <<cnt;
}