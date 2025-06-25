#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;
        multiset<int> ms;

        for (int i = 0; i < k; ++i) {
            string cmd;
            int n;
            cin >> cmd >> n;

            if (cmd == "I") {
                ms.insert(n);
            } else if (!ms.empty()) {
                if (n == 1) {
                    // 최댓값 삭제
                    auto it = prev(ms.end());
                    ms.erase(it);
                } else {
                    // 최솟값 삭제
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
        }
    }

    return 0;
}