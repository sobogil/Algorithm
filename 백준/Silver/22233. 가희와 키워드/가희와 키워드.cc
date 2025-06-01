#include<bits/stdc++.h>
using namespace std;

vector<string> split(string & str,char deli){
    vector<string> result;
    stringstream ss(str);
    string buf;
    while(getline(ss,buf,deli)){
        result.push_back(buf);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> memo;

    // 메모장 키워드 저장
    for (int i = 0; i < n; ++i) {
        string keyword;
        cin >> keyword;
        memo.insert(keyword);
    }

    // 글마다 처리
    for (int i = 0; i < m; ++i) {
        string line;
        cin >> line;

        vector<string> keywords = split(line, ',');

        for (const string &word : keywords) {
            memo.erase(word);  // 있으면 제거
        }

        cout << memo.size() << '\n';  // 남은 키워드 개수 출력
    }

    return 0;
}