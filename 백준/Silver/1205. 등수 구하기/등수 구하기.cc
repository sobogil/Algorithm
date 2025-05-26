#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, new_score, P;
    cin >> N >> new_score >> P;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    int rank = 1; 

    for (int i = 0; i < N; ++i) {
        if (scores[i] > new_score) {
            rank++;
        } else if (scores[i] == new_score) {
            continue;
        } else {
            break;
        }
    }

    if (N < P) {
        cout << rank << '\n';
    } else {
        if (rank > P) {
            cout << -1 << '\n';
        }
        else if (scores.back() >= new_score) {
            cout << -1 << '\n';
        }
        else {
            cout << rank << '\n';
        }
    }

    return 0;
}