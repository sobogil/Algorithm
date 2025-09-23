#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
map<string,char> mp;

void make_map(){
    mp["zero"] = '0';
    mp["one"] = '1';
    mp["two"] = '2';
    mp["three"] = '3';
    mp["four"] = '4';
    mp["five"] = '5';
    mp["six"] = '6';
    mp["seven"] = '7';
    mp["eight"] = '8';
    mp["nine"] = '9';
}
string ret="";

int solution(string s) {
    make_map();
    string temp="";
    for(auto c : s){
        if(isdigit(c)){
            ret+=c;
        }
        else{
            temp+=c;
            if (mp.count(temp)) {   // 맵에 존재하는 단어인지 확인
                ret += mp[temp];
                temp = "";
            }
        }
    }

    return stoi(ret);
}