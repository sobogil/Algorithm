#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string s1,s2;
int main(){
    cin >>s1>>s2;
    s1 = '0' +s1;
    s2 = '0' +s2;

    for(int i =0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(i==0||j==0)dp[i][j]=0;
            else if(s1[i]== s2[j])dp[i][j] = dp[i-1][j-1] +1;
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout <<dp[s1.size()-1][s2.size()-1];
}