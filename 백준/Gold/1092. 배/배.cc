#include<bits/stdc++.h>
using namespace std;

int n,crae[55],m,ti;
vector<int> box;
int main(){
    cin >>n;
    for(int i=0;i<n;i++)cin >>crae[i];
    cin >>m;
    box.resize(m);
    for(int i=0;i<m;i++)cin >>box[i];
    sort(crae,crae+n,greater<int>());
    sort(box.rbegin(),box.rend());

    if(crae[0] < box[0]){
        cout << -1;
        return 0;
    }
    
    while(box.size()){
        ti++;
        int idx = 0;
        for(int i=0;i<n;i++){
            while(idx<box.size()){
                if(crae[i]>=box[idx]){
                    box.erase(box.begin()+idx);
                    break;
                }else{
                    idx++;
                }
            }
        }
    }
    cout <<ti;
}