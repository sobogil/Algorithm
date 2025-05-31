#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=97)s[i]=(char)toupper(s[i]);
        else s[i]=(char)tolower(s[i]);
    }
    cout << s;
}