#include<bits/stdc++.h>
using namespace std;
string s;

bool check(string val,string target){
    int i=0,j=0;
    while(i<val.size() && j<target.size()){
        if(val[i]==target[j]){
            j++;
        }
        i++;
    }
    return j==target.size();
}
int main(){
    cin >> s;

    string temp;

    for(int i=1;;i++){
        temp += to_string(i);
        if(check(temp,s)){
            cout << i;
            return 0;
        }
    }
}