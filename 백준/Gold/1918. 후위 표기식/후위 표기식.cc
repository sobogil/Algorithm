#include<bits/stdc++.h>
using namespace std;
string s;

int prior(char op){
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}
int main(){
    cin >>s;
    stack<char> stk;

    for(auto c : s){
        if(isalpha(c)){
            cout << c;
        }
        else if(c=='('){
            stk.push(c);
        }
        else if(c==')'){
            while(stk.size() && stk.top()!= '('){
                cout << stk.top();stk.pop();
            }
            stk.pop();
        }
        else{
            while(stk.size() && prior(stk.top()) >= prior(c)){
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while(stk.size()){
        cout << stk.top();stk.pop();
    }
}