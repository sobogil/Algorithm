#include<bits/stdc++.h>
using namespace std;
string s,t;
int result;
void go(string cur) {
    if (cur.size() == s.size()) {
        if (cur == s) result = 1;
        return;
    }
    if (result) return; 

    if (cur.back() == 'A') {
        string next = cur;
        next.pop_back();
        go(next);
    }
    if (cur.front() == 'B') {
        string next = cur;
        reverse(next.begin(), next.end());
        next.pop_back();
        go(next);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>s>>t;
    go(t);
    if(result>0){
        cout << 1;
    }else{
        cout <<0;
    }
}