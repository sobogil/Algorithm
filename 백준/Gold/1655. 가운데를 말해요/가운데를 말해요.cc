#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;

    priority_queue<int> left;
    priority_queue<int,vector<int>, greater<int>> right;

    for(int i=0;i<n;i++){
        int k;
        cin >>k;
        if(!left.size() || left.top() > k) left.push(k);
        else right.push(k);

        int idx = (i/2)+1;

        if(left.size() > idx){
            right.push(left.top());
            left.pop();
        }else if(left.size() < idx){
            left.push(right.top());
            right.pop();
        }
        cout << left.top()<<'\n';
    }


}