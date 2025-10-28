#include<bits/stdc++.h>

using namespace std;

int doSomething(int nx){
    int num1 = nx, num2 = 0;

    num2 = num1 % 10 + num1 / 10;
    num2 %= 10;

    num1 = num1 % 10 * 10;

    return num1 + num2;
}

int main(){
    int n;

    cin >> n;

    int cnt = 0;
    int nx = n;

    while(1){
        int temp = doSomething(nx);

        cnt++;

        if(temp == n){
            break;
        }else{
            nx = temp;
        }
    }

    cout << cnt;
}