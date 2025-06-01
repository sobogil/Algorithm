#include<bits/stdc++.h>
using namespace std;

int n,k,p,x;

string led[10] = {
    "1111110", 
    "0110000", 
    "1101101", 
    "1111001",
    "0110011",
    "1011011", 
    "1011111",
    "1110000",
    "1111111", 
    "1111011"  
};
int get_diff(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (led[a][i] != led[b][i]) cnt++;
    }
    return cnt;
}

string make(int val,int k){
    string s = to_string(val);
    while(s.size() < k)s = "0" + s;
    return s;
}
int main(){
    cin >>n>>k>>p>>x;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(x==i)continue;

        string a = make(x,k);
        string b = make(i,k);

        int cnt = 0;
        for(int j=0;j<k;j++){
            int tempa = a[j] - '0';
            int tempb = b[j] - '0';
            cnt += get_diff(tempa,tempb);
        }

        if(cnt <= p)ans++;
    }
    cout <<ans;
}