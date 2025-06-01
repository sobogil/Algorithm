#include<bits/stdc++.h>
using namespace std;

int a,b,c;
int main(){
    cin >>a>>b>>c;
    cout <<a+b-c<<'\n';
    string s="";
    s += to_string(a) + to_string(b);
    int ab = stoi(s);
    cout << ab-c;
    
}