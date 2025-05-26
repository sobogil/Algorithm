#include<bits/stdc++.h>
using namespace std;

int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq; 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            pq.push(num);

            if (pq.size() > N) {
                pq.pop(); 
            }
        }
    }

    cout << pq.top() << '\n'; 
    return 0;
}
