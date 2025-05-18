#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (minHeap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            }
        } else {
            minHeap.push(x);
        }
    }

    return 0;
}