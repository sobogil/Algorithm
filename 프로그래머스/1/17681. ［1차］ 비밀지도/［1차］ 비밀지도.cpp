#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


string make_binary(int x){
    string ret ="";
    while(x){
        int val = x%2;
        ret = to_string(val) + ret;
        x/=2;
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> a(n);
    for(int i=0;i<n;i++){
        string ret ="";
        for(int j=0;j<n;j++){
            ret +=' ';
        }
        a[i] = ret;
    }
    for(int i=0;i<n;i++){
        string temp = make_binary(arr1[i]);
        int cnt =n-1;
        for(int j =temp.size()-1;j>=0;j--){
            if(temp[j]=='1')a[i][cnt] = '#';
            cnt--;
        }
    }
    for(int i=0;i<n;i++){
        string temp = make_binary(arr2[i]);
        int cnt =n-1;
        for(int j =temp.size()-1;j>=0;j--){
            if(temp[j]=='1')a[i][cnt] = '#';
            cnt--;
        }
    }
    vector<string> answer;
    return a;
}