#include<bits/stdc++.h>
using namespace std;

string s;
vector<string> split(string& s,char del){
    vector<string> result;
    stringstream ss(s);
    string buf;
    while(getline(ss,buf,del)){
        result.push_back(buf);
    }
    return result;
}

int main(){
    cin >> s;
    auto minusSplit = split(s,'-');
    int ret=0;
    vector<string> firstGroup = split(minusSplit[0], '+');
    for(string a : firstGroup){
        ret += stoi(a);
    }
    int cnt =0;

    for(int i=1;i<minusSplit.size();i++){
        vector<string> secondGroup = split(minusSplit[i], '+');
        cnt=0;
        for(auto l : secondGroup){
            cnt += stoi(l);
        }
        ret -= cnt;
    }
    cout << ret;
}