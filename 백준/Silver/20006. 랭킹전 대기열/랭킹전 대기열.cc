#include<bits/stdc++.h>
using namespace std;

int p,m,l;
string n;

int main(){
    cin >> p>>m;
    vector<vector<pair<int,string>>> rooms;
    for(int i=0;i<p;i++){
        cin >> l>>n;

        bool flag =0;
        for(int j=0;j<rooms.size();j++){
            auto &room = rooms[j];
            if(room.size() < m){
                int val = room[0].first;
                if(abs(val-l) <=10){
                    room.push_back({l,n});
                    flag=1;
                    break;
                }
            }
        }
        if(!flag){
            vector<pair<int,string>> room;
            room.push_back({l,n});
            rooms.push_back(room);
        }
    }

    for(auto &room: rooms){
        if(room.size()==m){
            cout << "Started!\n";
        }else{
            cout << "Waiting!\n";
        }
        sort(room.begin(),room.end(),[](auto a,auto b){
            return a.second < b.second;
        });
        for( auto s : room){
            cout << s.first<<" "<<s.second<<'\n';
        }
    }
}