#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> t;

int n,k,a,b,c,num,cnt;
int k1,k2,k3;
vector<tuple<int,int,int,int>>v;

int main(){
    cin >> n>>k;
    for(int i=0;i<n;i++){
        cin >> num;
        cin >>a>>b>>c;
        if(num ==k){
            k1=a;k2=b;k3=c;
        }
        v.push_back({a,b,c,num});
    }
    sort(v.begin(),v.end(),[](tuple<int,int,int,int> a,tuple<int,int,int,int> b){
        if(get<0>(a)==get<0>(b) && get<1>(a) == get<1>(b))return get<2>(a) > get<2>(b);
        if(get<0>(a)==get<0>(b)) return  get<1>(a) > get<1>(b);
        return  get<0>(a) > get<0>(b);
    });

    for(int i=0;i<v.size();i++){
        if(get<0>(v[i])!=k1 || get<1>(v[i])!=k2 || get<2>(v[i])!=k3)cnt++;
        if(k==get<3>(v[i])) {
            cout <<cnt+1;
            return 0;
        }
    }
}