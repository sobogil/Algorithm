#include<bits/stdc++.h>
using namespace std;

int n,a;
deque<int> v;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }

    int sum =0;
    sort(v.begin(),v.end());

    while(v.size()>1){

        if(v.size()<=1)break;
        int temp1 = v.back();
        int temp2 = v[v.size()-2];
        if(temp1 <=1)break;
        if(temp2 <=1)break;
        if(temp1==1||temp2==1||temp1==0||temp2==0)break;
        v.pop_back();
        v.pop_back();
        sum += temp1*temp2;
    }
    while(v.size()&& v.back()>0){
        sum += v.back();v.pop_back();
    }
    sort(v.begin(),v.end(),greater<int>());
    while(v.size() >1){
        int temp1 = v.back();
        int temp2 = v[v.size()-2];
        v.pop_back();
        v.pop_back();
        sum += temp1*temp2;
    }
    if(v.size()) sum+=v.back();
    cout << sum;
}