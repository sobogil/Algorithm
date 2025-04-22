#include<bits/stdc++.h>
using namespace std;

int n, a,ret;

int main(){
    
    cin >>n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++){
        cin >> a;
        pq.push(a);
    }

    while(pq.size()>1){
        int sum = pq.top();
        pq.pop();
        int temp = pq.top();
        pq.pop();
        sum += temp;
        ret += sum;
        pq.push(sum);
    }
    cout << ret;
}